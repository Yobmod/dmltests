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
