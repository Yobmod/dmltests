import tkinter as tk
from tkinter import (Menu, Label, PhotoImage, Button, Scale, Listbox,
                     messagebox, filedialog,
                     HORIZONTAL, TRUE, FALSE, LEFT, BOTTOM, X, W,
                     SUNKEN, GROOVE, )
from pygame import mixer
from mutagen.mp3 import MP3  # ASF, FLAC, MP4, OGG
import os
import threading
import time

from typing import List, Tuple

"""Are TRUE / FALSE needed?"""


root = tk.Tk()
mixer.init()  # initializing the mixer

statusbar = Label(root, text="Welcome to Melody", relief=SUNKEN, anchor=W)
statusbar.pack(side=BOTTOM, fill=X)

# Create the menubar
menubar = Menu(root)
root.config(menu=menubar)

# Set initial values
init_vol = 70
paused = False
muted = FALSE
filename: str
filename_path: str
playlist: List[str] = []

# add submenu1 commands


def browse_file() -> None:
    global filename_path
    filename_path = filedialog.askopenfilename()
    add_to_playlist(filename_path)


def add_to_playlist(filename: str) -> None:
    filename = os.path.basename(filename)
    index = 0
    playlistbox.insert(index, filename)
    playlist.insert(index, filename_path)
    index += 1


# Create the submenu1
subMenu1 = Menu(menubar, tearoff=0)
menubar.add_cascade(label="File", menu=subMenu1)
subMenu1.add_command(label="Open", command=browse_file)
subMenu1.add_command(label="Exit", command=root.destroy)

# add submenu2 commands


def about_us() -> None:
    messagebox.showinfo('About Melody', 'This is a music player built using Python Tkinter by @meee')


# Create the submenu2
subMenu2 = Menu(menubar, tearoff=0)
menubar.add_cascade(label="Help", menu=subMenu2)
subMenu2.add_command(label="About Us", command=about_us)


root.geometry('500x300')
root.minsize(300, 300)
root.title("Melody")
root.iconbitmap(R'assets\icons\melody.ico')


leftframe = tk.Frame(root)
leftframe.pack(side=LEFT, padx=30)

playlistbox = Listbox(leftframe)
playlistbox.pack()

addBtn = Button(leftframe, text="+ Add", command=browse_file)
addBtn.pack(side=LEFT)


def del_song() -> None:
    selected_song_from_box: Tuple[int] = playlistbox.curselection()
    if selected_song_from_box:
        selected_song = int(selected_song_from_box[0])
        playlistbox.delete(selected_song)
        playlist.pop(selected_song)


delBtn = Button(leftframe, text="- Del", command=del_song)
delBtn.pack(side=LEFT)


rightframe = tk.Frame(root)
rightframe.pack()


filelabel = Label(rightframe, text='Lets make some noise!')
filelabel.pack(pady=10)

lengthlabel = Label(rightframe, text='Total Length : --:--')
lengthlabel.pack()

currenttimelabel = Label(rightframe, text='Current Time : --:--', relief=GROOVE)
currenttimelabel.pack()


def start_count(total_time: int) -> None:
    global paused

    # mixer.music.get_busy(): - Returns FALSE when we press the stop button (music stop playing)
    # Continue - Ignores all of the statements below it. We check if music is paused or not.
    current_time = 0
    while current_time <= total_time and mixer.music.get_busy():
        if paused:
            continue
        else:
            mins, secs = divmod(current_time, 60)
            mins = round(mins)
            secs = round(secs)
            timeformat = '{:02d}:{:02d}'.format(mins, secs)
            currenttimelabel['text'] = "Current Time" + ' - ' + timeformat
            time.sleep(1)
            current_time += 1


def show_details(play_song: str) -> None:
    filelabel['text'] = "Playing" + ' - ' + os.path.basename(play_song)
    file_data = os.path.splitext(play_song)

    if file_data[1] == '.mp3':
        audio = MP3(play_song)
        total_length = audio.info.length
    elif file_data[1] == '.wav':
        a = mixer.Sound(play_song)
        total_length = a.get_length()
    else:
        try:
            a = mixer.Sound(play_song)
            total_length = a.get_length()
        except Exception as e:
            print(e)

    # div - total_length/60, mod - total_length % 60
    mins, secs = divmod(total_length, 60)  # returns (time//60, remainder)
    mins = round(mins)
    secs = round(secs)
    timeformat = '{:02d}:{:02d}'.format(mins, secs)
    lengthlabel['text'] = "Total Length" + ' - ' + timeformat

    t1 = threading.Thread(target=start_count, args=(total_length, ))
    t1.start()


def pause_music() -> None:
    global paused
    paused = TRUE
    mixer.music.pause()
    statusbar['text'] = "Music Paused"


def play_music() -> None:
    global paused

    if paused:
        mixer.music.unpause()
        statusbar['text'] = "Music Resumed"
        paused = FALSE
    else:
        try:
            stop_music()
            time.sleep(1)
            selected_song_from_box: Tuple[int] = playlistbox.curselection()
            selected_song = int(selected_song_from_box[0])
            play_it = playlist[selected_song]
            mixer.music.load(play_it)
            mixer.music.play()
        except NameError as e:  # filename not defined
            statusbar['text'] = "Please select a file to play"
            print(e)
        except IndexError as e:  # no files in the playlistbox tuple
            statusbar['text'] = "Choose a file from the playlist"
            print(e)
        except Exception as e:
            messagebox.showerror('File not found, or unknown file type. Please check again.')
            print(e)
        else:
            show_details(play_it)
            statusbar['text'] = "Playing music" + ' - ' + os.path.basename(play_it)


def stop_music() -> None:
    mixer.music.stop()
    statusbar['text'] = "Music Stopped"


def rewind_music() -> None:
    play_music()
    statusbar['text'] = "Music Rewound to start"


def set_vol(val: str) -> None:
    volume = int(val) / 100
    mixer.music.set_volume(volume)
    # set_volume of mixer takes value only from 0 to 1


def mute_music() -> None:
    global muted
    if muted:  # Unmute the music
        mixer.music.set_volume(0.7)
        volumeBtn.configure(image=volumePhoto)
        scale.set(70)
        muted = FALSE
    else:  # mute the music
        mixer.music.set_volume(0)
        volumeBtn.configure(image=mutePhoto)
        scale.set(0)
        muted = TRUE


middleframe = tk.Frame(rightframe)
middleframe.pack(pady=30, padx=30)


playPhoto = PhotoImage(file='assets/icons/play.png')
playBtn = Button(middleframe, image=playPhoto, command=play_music)
playBtn.grid(row=0, column=1, padx=10)

stopPhoto = PhotoImage(file='assets/icons/stop.png')
stopBtn = Button(middleframe, image=stopPhoto, command=stop_music)
stopBtn.grid(row=0, column=2, padx=10)

pausePhoto = PhotoImage(file='assets/icons/pause.png')
pauseBtn = Button(middleframe, image=pausePhoto, command=pause_music)
pauseBtn.grid(row=0, column=3, padx=10)


bottomframe = tk.Frame(rightframe)
bottomframe.pack()


mutePhoto = PhotoImage(file='assets/icons/mute.png')
volumePhoto = PhotoImage(file='assets/icons/volume.png')
volumeBtn = Button(bottomframe, image=volumePhoto, command=mute_music)
volumeBtn.grid(row=0, column=1)


rewindPhoto = PhotoImage(file='assets/icons/rewind.png')
rewindBtn = Button(bottomframe, image=rewindPhoto, command=rewind_music)
rewindBtn.grid(row=0, column=0)

scale = Scale(bottomframe, from_=0, to=100, orient=HORIZONTAL, command=set_vol)
scale.set(init_vol)
mixer.music.set_volume(init_vol/100)
scale.grid(row=0, column=2, pady=15, padx=30)


def on_closing() -> None:
    stop_music()
    root.destroy()
    print('App closed')


if __name__ == "__main__":
    root.protocol("WM_DELETE_WINDOW", on_closing)
    root.mainloop()
