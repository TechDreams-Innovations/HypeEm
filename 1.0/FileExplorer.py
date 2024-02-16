import tkinter as tk
from tkinter.filedialog import askopenfilename

def browse():
   f_path = askopenfilename(initialdir="/",
      title="Select File", filetypes=(("Text files","*.txt*"),("All Files","*.*")))
   file_explorer.configure(text="File Opened: "+f_path)
root = tk.Tk()
root.title("File Explorer")
root.geometry("750x350")
root.config(background="black")
file_explorer = tk.Label(root, text="File Explorer",
   font=("Verdana", 14, "bold"),
   width=100,
   height=4, fg="white", bg="navy blue")
button=tk.Button(root, text="Browse Folder", font =("Sans Serif", 14),
   command=browse)
file_explorer.pack()
button.pack(pady=30)
root.mainloop()
