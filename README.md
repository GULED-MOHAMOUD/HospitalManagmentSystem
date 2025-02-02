# Hospital Management System(HMS)

## 1. Introduction
This Hospital Management System (HMS) is designed to provide a way to manage patient records. The system will allow users to add, view, search, save, and load patient information in an organized manner. By implementing this we think it saves time, energy and also many more.

## Pre-requisites
   Before starting this documentation this documentation will assume you know the basics of C++ programming language, Functions, Pointers, Arrays, 
   and  file input/output. But if you are not familiar with this  checkout this link out.

 **Great tutorial to start:** [C++ basics](https://cplusplus.com/doc/tutorial/)

  **Must know programming concept:** [C++ functions](https://www.geeksforgeeks.org/functions-in-cpp/)

  **Arrays:** [Start here ](https://cplusplus.com/doc/tutorial/arrays/)

  **C++ main concept: ** [Pointers](https://www.geeksforgeeks.org/cpp-pointers/)

  **learn how to handle files:** [File handling](https://www.learncpp.com/cpp-tutorial/basic-file-io/)

 ## 2. Objectives

   **The main objectives of the HMS are:** 

**•	Efficient Patient Record Management:** Provide a structured way to store and access patient details.

**•	User-Friendly Interface:** Ensure easy navigation and clear prompts for hospital staff.

**•	Data Persistence:** Allow patient records to be saved and loaded from a file for long-term storage.

**•	Performance:** Ensure smooth operation for up to 100 patient records without performance degradation.

## 3. Functional Requirements

### 3.1 User Operations

 ### 1.	Add a Patient:

     Users should be able to enter patient details including ID, Name, Age, and Disease.

     The system should validate ID and Age as numeric values to prevent incorrect input.

 **2.View All Patients:**

          The system should display a list of all saved patient records.

          If no records exist, it should notify the user accordingly.

**3.Search for a Patient:**

     Users should be able to find a patient by ID.
     If the ID does not exist, an appropriate message should be displayed.

**4.	Save Patient Data to File:**

      Patient records should be saved to a CSV file format (patients.txt) to ensure easy retrieval.

      The system should notify the user when saving is successful.

**5.	Load Patient Data from File:**

        The system should retrieve patient records from the saved file and store them in memory for further use.

        If the file does not exist, the system should handle the error gracefully.

   ## 3.2 Data Structure & Storage
   **Each patient record consists of:**

    > ID (Integer): A patient identifier number.
    > NAME (String): A patient's full name.
    > Age (Integer): Patients Age.
    > Disease(string): Description of the patient's illness.

The system will use an **array** of structures to store up to **100 patient records** in memory.

## 3.3 Error Handling & Validation
To ensure smooth operation, the system will:

**•	Validate Numeric Fields:** Prevent invalid input for ID and Age (e.g., rejecting letters or symbols).

**•	Prevent Exceeding Patient Capacity:** Notify users if the system reaches the 100-patient limit.

**•	Handle File Errors:** Alert users if the file is missing, corrupted, or unreadable.

## 4. Non-Functional Requirements
  ### 4.1 Usability

•	The system will use a simple, menu-based command-line interface.

### 4.2 Performance

•	The system should handle up to 100 patient records efficiently without lag.

### 4.3 Reliability & Data Integrity

•	Patient records should remain consistent and should not be lost due to crashes or incorrect operations.

### 4.4 Security Considerations

•	The current version does not include authentication but can be extended in the future for role-based access control.

### 4.5 Compatibility

•	The system should run on any standard C++ compiler and should be platform-independent except the older versions of IDEs.

## 5. Implementation Details

  •       Programming Language: C++
  •	  Libraries Used: <iostream>, <fstream>, <string>
  •	  Storage Method: CSV file format for persistence
  •	  Development Environment: VS Code. 

## 6. User Interface Design

  The system will have a simple text-based menu, allowing users to navigate options using numbered choices:

             -----------------------------------
             |    HOSPITAL MANAGEMENT SYSTEM   |
             -----------------------------------
              1. Add Patient
              2. Save Patient Info to File
              3. Search for a Patient
              4. View All Patients
              5. Load Data from File
              6. Exit
              Enter your choice:


 ## 7. Testing & Quality Assurance
   The system will be tested to ensure:
 •	Correct data entry and retrieval – Verifying that user input is processed correctly.
 •	Handling of edge cases – Testing with invalid inputs, full capacity, and missing files.
 •	Data validation – Ensuring only valid patient details can be entered.
 •	File operations – Checking that saving and loading functions work as expected.

## 8. Future Enhancements
•	To save more information about patient (like **Address**, **phone number** etc…).

•	Management of other hospital staffs ( like **Doctors**, **Nurses**, **Other hospital managements**)

•	Deletion of the **saved Patients**.

## 9. Conclusion

**The Hospital Management System** is a simple and effective solution for managing **patient records efficiently**. It provides essential functionalities such as **adding**, **searching saving**, and **loading patient data**, ensuring that hospital staff can access accurate records at any time.
**Next Steps:** Implementation, Testing, and Continuous Improvement!.


