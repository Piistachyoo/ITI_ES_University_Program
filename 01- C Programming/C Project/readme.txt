IMT Bank System!

Admin username: 1346
Admin password: 6431
** Admin username and password are defined in admin.h file and can be changed **

Features:
- Project loads database from .txt file and reads accounts data from the same file on startup (if you delete the file it will create it again but you lose data)
- The program generates a 10-digit bank ID and verifies that the ID is not repeated and doesn't belong to any another user
- The program generates a 4-digit pin for new accounts
- The program verifies that the user enters 4 names in the name section, less than 4 words are not accepted!
- If the user's age is below 21, the program will ask for his guardian's ID
- Account status can be changed by admin between active, restricted, and closed
- Users can change their passwords at any time (program double checks for old password before changing)
- Users can deposit and withdraw cash from their account
- Users can send cash to another person's account (both accounts' status must be active)