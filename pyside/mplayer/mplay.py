    def _menubar(self) -> None:
        menubar = Menu(self.parent)
        self.parent.config(menu=menubar)
        # Create the submenu1
        subMenu1 = Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=subMenu1)
        subMenu1.add_command(label="Open", command=self.browse_file)
        subMenu1.add_command(label="Exit", command=self.parent.destroy)
        # Create the submenu2
        subMenu2 = Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Help", menu=subMenu2)
        subMenu2.add_command(label="About Us", command=self.about_us)

    def pause_music(self) -> None:
        if self.playing:
            self.paused = True
            mixer.music.pause()
            self.statusbar['text'] = "Music Paused"

    def get_selected_song_num(self) -> None:
        try:
            selected_song_from_box: Tuple[int] = self.playlistbox.curselection()
            self.selected_song_num = int(selected_song_from_box[0])
        except IndexError as e:  # no files in the playlistbox tuple
            self.statusbar['text'] = "Choose a file from the playlist"
            if DEBUG: print(e)
        except Exception as e:
            messagebox.showerror('File not found, or unknown file type. Please check again.')
            if DEBUG: print(e)

    def stop_music(self) -> None:
        if self.playing:
            self.playing = False
            self.current_song = None
            mixer.music.stop()
            self.statusbar['text'] = "Music Stopped"

    def rewind_music(self) -> None:
        if self.playing:
            self.stop_music()
            time.sleep(0.5)
            self.play_music()
            self.statusbar['text'] = "Music Rewound to start"

    def set_vol(self, val: str) -> None:
        vol_float = float(val)
        volume = int(vol_float) / 100
        mixer.music.set_volume(volume)
        # set_volume of mixer takes value only from 0 to 1

    def mute_music(self) -> None:
        if self.muted:  # Unmute the music
            mixer.music.set_volume(0.7)
            self.volumeBtn.configure(image=self.volumePhoto)
            self.scale.set(70)
            self.muted = False
        else:  # mute the music
            mixer.music.set_volume(0)
            self.volumeBtn.configure(image=self.mutePhoto)
            self.scale.set(0)
            self.muted = True

    def _create_bottomframe(self) -> None:
        self.bottomframe = Frame(self.rightframe)
        self.bottomframe.pack()

        self.mutePhoto = PhotoImage(file=self.assets_path + '/icons/mute.png')
        self.volumePhoto = PhotoImage(file=self.assets_path + '/icons/volume.png')
        self.volumeBtn = Button(self.bottomframe, image=self.volumePhoto, command=self.mute_music)
        self.volumeBtn.grid(row=0, column=1)

        self.rewindPhoto = PhotoImage(file=self.assets_path + '/icons/rewind.png')
        rewindBtn = Button(self.bottomframe, image=self.rewindPhoto, command=self.rewind_music)
        rewindBtn.grid(row=0, column=0)

        self.scale = Scale(self.bottomframe, from_=0, to=100, orient=HORIZONTAL, command=self.set_vol)
        self.scale.set(self.init_vol)
        mixer.music.set_volume(self.init_vol / 100)
        self.scale.grid(row=0, column=2, pady=15, padx=30)

    def on_closing(self) -> None:
        try:
            self.stop_music()
            self.parent.destroy()
        except Exception as e:
            if DEBUG: print(e)
        else:
            print('App closed')
