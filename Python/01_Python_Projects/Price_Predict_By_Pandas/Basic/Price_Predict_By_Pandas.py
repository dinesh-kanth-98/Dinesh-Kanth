from tkinter import *
import tkinter as tk
import pandas as pd

def clear_label_status():
    price_entry.delete(0, tk.END)
    
def Search_Data():
    try:
        Location = Location_entry.get()
        Bedrooms = int(Bhk_entry.get())
        Area = int(Total_Sqft_Entry.get())
    except ValueError:
        price_entry.delete(0, tk.END)  # Clear the existing value
        price_entry.insert(tk.END, No_Data_string)
        root.after(3000, clear_label_status)

        return
        
    print(Location,Bedrooms,Area)
    
    df = pd.read_csv('Hyderabad.csv')

    filtered_df = df[(df['Location'] == Location) & (df['Area'] == Area) & (df['No. of Bedrooms'] == Bedrooms)]

    if not filtered_df.empty:
        print("Prices of matched rows:")
        for predicted_price in filtered_df['Price']:
            print(predicted_price)
            price_entry.delete(0, tk.END)  # Clear the existing value
            price_entry.insert(tk.END, predicted_price)

            break;
    else:
        print("No matching rows found.")
        price_entry.delete(0, tk.END)  # Clear the existing value
        price_entry.insert(tk.END, No_Data_string)
        root.after(3000, clear_label_status)


root=tk.Tk()
root.geometry('500x300')
root.title("HOUSE PRICE PREDICTION")
No_Data_string="No Matching Data Found."


title_label=Label(root,text='HOUSE PRICE PREDICTION',fg='Black',font=20)
title_label.grid(row=0,column=3,padx=5,pady=10)

Location_label=Label(root,text='Select the Location',fg='Black',font=16)
Location_label.grid(row=2,column=2,padx=5,pady=10)

Location_entry=Entry(root)
Location_entry.grid(row=2,column=3,padx=5,pady=10)

Bhk_label=Label(root,text='Enter BHK',fg='Black',font=16)
Bhk_label.grid(row=3,column=2,padx=5,pady=10)

Bhk_entry=Entry(root)
Bhk_entry.grid(row=3,column=3,padx=5,pady=10)

Total_Sqft_label=Label(root,text='Enter Total Sqft',fg='Black',font=16)
Total_Sqft_label.grid(row=4,column=2,padx=5,pady=10)

Total_Sqft_Entry=Entry(root)
Total_Sqft_Entry.grid(row=4,column=3,padx=5,pady=10)

Price_Predict_Button=Button(root,text="Predict Price",fg='Black',font=16, command=Search_Data )
Price_Predict_Button.grid(row=6,column=3,padx=5,pady=10)

price_status = Label(root, text="Price", fg='Black',font=16)
price_status.grid(row=7, column=2, padx=5,pady=10)

price_entry = Entry(root, width=30)
price_entry.grid(row=7, column=3, padx=35,pady=20)
        
root.mainloop()