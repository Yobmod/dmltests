import tkinter as tk
from tkinter.ttk import Frame

# name and design the box

def main():
  
    root = tk.Tk()
    root.geometry('400x500')
    app = Example(root)
    root.mainloop()  

class Example(Frame):
  
    def __init__(self, parent):
        Frame.__init__(self, parent)   
         
        self.parent = parent
        self.initUI()
        
# define the functions
    def initUI(self):
      
        self.parent.title("DML GUI")
        #self.style = Style()
        #self.style.theme_use("default")
        #Style().configure("TFrame", background="#333")
        
        frame = Frame(self, relief=RAISED, borderwidth=1)
        frame.pack(fill=BOTH, expand=True)
        
        self.pack(fill=BOTH, expand=True)
        
        minc = Image.open("Tulips.jpg")
        mincol = ImageTk.PhotoImage(minc)
        label3 = Label(self, image=mincol)
        label3.image = mincol
        label3.place(x=170, y=50) 
        
        def Q_datapath():
            datapath = tk.Toplevel()
            datapath.geometry('300x200')
            datapath.title("Help: Data Path")
            def close_help():
                datapath.destroy()
            Button_C = tk.Button(datapath, text="Close", bg="darksalmon", command=close_help)
            Button_C.pack(pady=10, ipadx=20)
            
        def Q_savepath():
            savepath = tk.Toplevel()
            savepath.geometry('300x200')
            savepath.title("Help: Save Path")
            def close_help():
                savepath.destroy()
            Button_close_help = tk.Button(savepath, text="Close", bg="darksalmon", command=close_help)
            Button_close_help.pack(pady=10, ipadx=20)
            
        def close_all():
            self.destroy()  
                 
        def go():
            print("this will run the programme eventually...") 
              
# label and give jobs to the buttons. Pack/grid/place to place them         
        Button_datapath_help = tk.Button(self, text="?", fg="white", bg ="blue", command=Q_datapath)
        Button_datapath_help.pack(pady=5, ipadx=5)
        
        Button_savepath_help = tk.Button(self, text="?", fg="black", bg="yellow", command=Q_savepath)
        Button_savepath_help.pack(pady=5, ipadx=5)
        
        Button_exit = tk.Button(self, text="Exit", fg="black", bg="red", command=close_all)
        Button_exit.pack(pady=5, ipadx=20)
        
        Button_go = tk.Button(self, text="Go", fg="white", bg ="dark green", command=go)
        Button_go.pack(pady=5, ipadx=20)





if __name__ == '__main__':
    main()  

