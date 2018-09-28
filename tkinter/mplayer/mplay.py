import tkinter as tk
from tkinter import Menu, Label, PhotoImage, Button, HORIZONTAL, Scale, messagebox, filedialog, TRUE, FALSE, BOTTOM, X, W, SUNKEN
from pygame import mixer
from mutagen.mp3 import MP3
import os

"""Are TRUE / FALSE needed?"""


root = tk.Tk()
mixer.init()  # initializing the mixer

# Create the menubar
menubar = Menu(root)
root.config(menu=menubar)

# add submenu1 commands


def browse_file() -> None:
    global filename                           # TODO change from global?
    filename = filedialog.askopenfilename()   # TODO set start folder, set file types
    show_details()
    statusbar['text'] = "File selected" + ' - ' + os.path.basename(filename)


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


# Set initial values
init_vol = 70
paused = False
muted = FALSE

root.geometry('300x300')
root.title("Melody")
root.iconbitmap(R'assets\icons\melody.ico')

filelabel = Label(root, text='Lets make some noise!')
filelabel.pack(pady=10)

lengthlabel = Label(root, text='Total Length : --:--')
lengthlabel.pack()


def show_details() -> None:
    filelabel['text'] = "Playing" + ' - ' + os.path.basename(filename)
    file_data = os.path.splitext(filename)

    if file_data[1] == '.mp3':
        audio = MP3(filename)
        total_length = audio.info.length
    elif file_data[1] == '.wav':
        a = mixer.Sound(filename)
        total_length = a.get_length()
    else:
        try:
            a = mixer.Sound(filename)
            total_length = a.get_length()
        except Exception as e:
            print(e)

    # div - total_length/60, mod - total_length % 60
    mins, secs = divmod(total_length, 60)
    mins = round(mins)
    secs = round(secs)
    timeformat = '{:02d}:{:02d}'.format(mins, secs)
    lengthlabel['text'] = "Total Length" + ' - ' + timeformat


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
            mixer.music.load(filename)
            mixer.music.play()
            show_details()
        except NameError:  # filename not defined
            statusbar['text'] = "Please select a file to play"
        except Exception as e:
            messagebox.showerror('File not found, or unknown file type. Please check again.')
            print(e)
        else:
            statusbar['text'] = "Playing music" + ' - ' + os.path.basename(filename)


def stop_music() -> None:
    mixer.music.stop()
    statusbar['text'] = "Music Stopped"


def rewind_music() -> None:
    play_music()
    statusbar['text'] = "Music Rewinding"


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


middleframe = tk.Frame(root)
middleframe.pack(pady=10)


playPhoto = PhotoImage(file='assets/icons/play.png')
playBtn = Button(middleframe, image=playPhoto, command=play_music)
playBtn.grid(row=0, column=1, padx=10)

stopPhoto = PhotoImage(file='assets/icons/stop.png')
stopBtn = Button(middleframe, image=stopPhoto, command=stop_music)
stopBtn.grid(row=0, column=2, padx=10)

pausePhoto = PhotoImage(file='assets/icons/pause.png')
pauseBtn = Button(middleframe, image=pausePhoto, command=pause_music)
pauseBtn.grid(row=0, column=3, padx=10)


bottomframe = tk.Frame(root)
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

statusbar = Label(root, text="Welcome to Melody", relief=SUNKEN, anchor=W)
statusbar.pack(side=BOTTOM, fill=X)

root.mainloop()
