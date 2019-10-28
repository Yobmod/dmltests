import tkinter as tk

window = tk.Tk()

window.title("my maths project")

window.geometry("500x500")

# FUNCTIONS


def fare_calculater():
    distance = int(entry_km.get())
    fare = 3 + (distance * 5)
    print(fare)
    return fare


def fare_display():
    showup = fare_calculater()

    fare_display = tk.Text(master=window, height=10, width=30)
    fare_display.grid(column=0, row=5)
    fare_display.insert(tk.END, showup)

# LABEL


label_head = tk.Label(text="Hello User!. welcome to the app", font=("The New Roman", 25))
label_head.grid()

label_enter = tk.Label(text="Enter the distence commuted by the passanger below")
label_enter.grid(column=0, row=1)


# ENTRY

entry_km = tk.Entry()
entry_km.grid(column=0, row=2)

# button

button_submit = tk.Button(text="submit", bg="green", command=fare_display)
button_submit.grid(column=0, row=3)

window.mainloop()
print("done")
