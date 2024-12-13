import pandas as pd
import json

# Load consultation_data.json file
with open("consultation_data.json", "r") as file:
    data = json.load(file)

# Convert JSON data to a DataFrame
df = pd.DataFrame(data)

# Question 1: Percentage of missing values for firstName, lastName, and DOB
def calculate_missing_percentage(column):
    total = len(df)
    missing = df[column].apply(lambda x: x == "" or pd.isna(x)).sum()
    return round((missing / total) * 100, 2)

missing_firstName = calculate_missing_percentage("firstName")
missing_lastName = calculate_missing_percentage("lastName")
missing_DOB = calculate_missing_percentage("DOB")

# Combine results as a comma-separated string
missing_values_percentage = f"{missing_firstName},{missing_lastName},{missing_DOB}"
print("Missing Values Percentage:", missing_values_percentage)

# Question 2: Percentage of female gender after imputing missing values with mode
df["gender"].fillna(df["gender"].mode()[0], inplace=True)
female_percentage = round((df["gender"].str.lower() == "female").sum() / len(df) * 100, 2)
print("Female Percentage After Imputation:", female_percentage)

# Question 3: Add ageGroup column and count Adults
def categorize_age(age):
    if age <= 12:
        return "Child"
    elif 13 <= age <= 19:
        return "Teen"
    elif 20 <= age <= 59:
        return "Adult"
    else:
        return "Senior"

df["ageGroup"] = df["age"].apply(categorize_age)
adult_count = (df["ageGroup"] == "Adult").sum()
print("Adult Count:", adult_count)

# Question 4: Average number of medicines prescribed
average_medicines = round(df["prescribedMedicines"].mean(), 2)
print("Average Number of Medicines Prescribed:", average_medicines)

# Question 5: 3rd most frequently prescribed medicineName
medicine_counts = df["medicineName"].value_counts()
third_most_frequent_medicine = medicine_counts.index[2] if len(medicine_counts) >= 3 else None
print("3rd Most Frequently Prescribed Medicine:", third_most_frequent_medicine)

# Question 6: Percentage distribution of active and inactive medicines
active_inactive_counts = df["medicineStatus"].value_counts(normalize=True) * 100
active_percentage = round(active_inactive_counts.get("active", 0), 2)
inactive_percentage = round(active_inactive_counts.get("inactive", 0), 2)
percentage_distribution = f"{active_percentage},{inactive_percentage}"
print("Percentage Distribution of Active and Inactive Medicines:", percentage_distribution)
