#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char firstName[30];
    char middleName[30];
    char lastName[30];
    char company[30];
    char phone[10];
    char email[30];
    char address[30];
    char birthday[11];
    char website[30];
    char note[20];
    int status;
} Contact;

Contact getContact();
int writeContactsToFile(Contact *allContacts, int count, const char *fileName);
int mainMenu();
int readContactsFromFile(Contact *allContacts, int *count, const char *fileName);
int DetailMenuUI();
int getNoDetail();
void Line();
void getString(char *str, int length);
void PressEnterToContinue();
void contactsDetailsUI(int no, Contact *allContacts);
void savingSuccess();
char searchName(char inputSearchName[20]);
void chooseAlert(int from, int to);
void chooseNoAlert();
void detailMenuHandle(int no, int *count, Contact *allContacts);
void searchContactHandle(int *count, Contact *allContacts, char inputSearchName[20]);
void AddToFavouritesHandle(int no, Contact *allContacts, int *count);
void DeleteContactHandle(int no, Contact *allContacts, int *count);
void printAllContacts(int n, Contact *allContacts);
void printContact(int n, Contact *allContacts);
void printFavouritesContact(int n, Contact *allContacts);
int UpdateContactMenu();
void deletingSuccess();
void UpdateContactFNameHandle(int no, Contact *allContacts, int *count);
void UpdateContactMNameHandle(int no, Contact *allContacts, int *count);
void UpdateContactLNameHandle(int no, Contact *allContacts, int *count);
void UpdateContactCompanyHandle(int no, Contact *allContacts, int *count);
void UpdateContactEmailHandle(int no, Contact *allContacts, int *count);
void UpdateContactPhoneHandle(int no, Contact *allContacts, int *count);
void UpdateContactAddressHandle(int no, Contact *allContacts, int *count);
void UpdateContactBirthdayHandle(int no, Contact *allContacts, int *count);
void UpdateContactWebsiteHandle(int no, Contact *allContacts, int *count);
void UpdateContactNoteHandle(int no, Contact *allContacts, int *count);
void UpdatingSuccess();

int main()
{
    Contact *allContacts = (Contact *)malloc(100 * sizeof(Contact));
    int i, count = 0, mainChoice, no;
    char inputSearchName[20];
    readContactsFromFile(allContacts, &count, "contacts.csv");
    do
    {
        int mainChoice = mainMenu();
        switch (mainChoice)
        {
        case 1:
            inputSearchName[20] = searchName(inputSearchName);
            searchContactHandle(&count, allContacts, inputSearchName);
            no = getNoDetail();
            if (no == 0)
                break;
            else if (no > 0 && no <= count)
            {
                detailMenuHandle(no, &count, allContacts);
            }
            else
            {
                chooseNoAlert();
                break;
            }
            break;
        case 2:
            allContacts[count] = getContact();
            count++;
            writeContactsToFile(allContacts, count, "contacts.csv");
            savingSuccess();
            break;
        case 3:
            readContactsFromFile(allContacts, &count, "contacts.csv");
            printFavouritesContact(count, allContacts);
            no = getNoDetail();
            if (no == 0)
                break;
            else if (no > 0 && no <= count)
            {
                detailMenuHandle(no, &count, allContacts);
            }
            else
            {
                chooseNoAlert();
                break;
            }
            break;
        case 4:
            readContactsFromFile(allContacts, &count, "contacts.csv");
            printAllContacts(count, allContacts);
            no = getNoDetail();
            if (no == 0)
                break;
            else if (no > 0 && no <= count)
            {
                detailMenuHandle(no, &count, allContacts);
            }
            else
            {
                chooseNoAlert();
                break;
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            chooseAlert(1, 5);
        }
    } while (mainChoice != 5);
    return 0;
}

int UpdateContactMenu()
{
    int choice;
    Line();
    printf(" ENTER CONTACT YOU WANT TO UPDATE\n");
    Line();
    printf(" 1. First Name   2. Middle Name   3. Last Name ");
    printf("\n 4. Company     5. Phone         6. Email ");
    printf("\n 7. Address     8. Birthday      9. Website ");
    printf("\n 10. Note \n");
    Line();
    printf(" #CHOICE: ");
    scanf("%d", &choice);
    return choice;
}

void savingSuccess()
{
    Line();
    printf(" Saving.. Success!\n");
    Line();
    PressEnterToContinue();
}

int getNoDetail()
{
    int no;
    Line();
    printf("INPUT CONTACT NO TO VIEWS DETAILS OR INPUT 0 TO BACK MAIN MENU: ");
    scanf("%d", &no);
    return no;
}

void chooseNoAlert()
{
    printf("\nPlease, Choose no from the list!\n");
    PressEnterToContinue();
}

void chooseAlert(int from, int to)
{
    printf("\nPlease, Choose numbers between %s and %s!\n\n", from, to);
    PressEnterToContinue();
}

int mainMenu()
{
    int choice;
    Line();
    printf("      --- VTC ACADEMY CONTACT MANAGEMENT ---\n");
    Line();
    printf("  1. SEARCH YOUR CONTACT\n");
    printf("  2. ADD CONTACT\n");
    printf("  3. DISPLAY FAVOURITES CONTACT\n");
    printf("  4. DISPLAY ALL CONTACT\n");
    printf("  5. EXIT APPLICATION\n");
    Line();
    printf(" #YOUR CHOICE: ");
    scanf("%d", &choice);
    Line();
    return choice;
}

char searchName(char inputSearchName[20])
{
    printf("Enter name you want to search: ");
    getString(inputSearchName, 20);
    return inputSearchName[20];
}

void contactsDetailsUI(int no, Contact *allContacts)
{
    Line();
    printf(" CONTACT DETAILS\n");
    Line();
    printf(" First Name:  %s\n", (allContacts + no)->firstName);
    printf(" Middle Name: %s\n", (allContacts + no)->middleName);
    printf(" Last Name:   %s\n", (allContacts + no)->lastName);
    printf(" Company:     %s\n", (allContacts + no)->company);
    printf(" Phone:       %s\n", (allContacts + no)->phone);
    printf(" Email:       %s\n", (allContacts + no)->email);
    printf(" Address:     %s\n", (allContacts + no)->address);
    printf(" Birthday:    %s\n", (allContacts + no)->birthday);
    printf(" Website:     %s\n", (allContacts + no)->website);
    printf(" Note:        %s\n", (allContacts + no)->note);
    Line();
}

void UpdateContactFNameHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->firstName, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactMNameHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->middleName, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactLNameHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->lastName, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactCompanyHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->company, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactPhoneHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->phone, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactBirthdayHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->birthday, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactEmailHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->email, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactAddressHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->address, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactNoteHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->address, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

void UpdateContactWebsiteHandle(int no, Contact *allContacts, int *count)
{
    int c = *count;
    getString((allContacts + no)->website, 30);
    writeContactsToFile(allContacts, c, "contacts.csv");
}

int DetailMenuUI()
{
    int choice;
    printf(" 1. ADD TO FAVOURITES\n");
    printf(" 2. UPDATE\n");
    printf(" 3. DELETE\n");
    printf(" 4. ADD FIELD\n");
    printf(" 5. BACK TO MAIN MENU\n");
    Line();
    printf(" #CHOICE: ");
    scanf("%d", &choice);
    Line();
    return choice;
}

Contact getContact()
{
    Contact allContacts;
    printf(" First Name: ");
    getString(allContacts.firstName, 50);
    printf(" Middle Name: ");
    getString(allContacts.middleName, 50);
    printf(" Last Name: ");
    getString(allContacts.lastName, 50);
    printf(" Company: ");
    getString(allContacts.company, 50);
    printf(" Phone: ");
    getString(allContacts.phone, 50);
    printf(" Email: ");
    getString(allContacts.email, 50);
    printf(" Address: ");
    getString(allContacts.address, 50);
    printf(" Birthday: ");
    getString(allContacts.birthday, 50);
    printf(" Website: ");
    getString(allContacts.website, 50);
    printf(" Note: ");
    getString(allContacts.note, 50);
    allContacts.status = 0;
    return allContacts;
}

void AddToFavouritesHandle(int no, Contact *allContact, int *count)
{
    (allContact + no)->status = 1;
}

void printAllContacts(int n, Contact *allContacts)
{
    printf("  %-2s  | %-29s \n", "No", "Name");
    for (int i = 0; i < n; i++)
    {
        printContact((i + 1), (allContacts + i));
    }
}

void printContact(int n, Contact *allContacts)
{
    printf(" %2d   | %s %s \n", n, allContacts->lastName, allContacts->firstName);
}

void printFavouritesContact(int n, Contact *allContacts)
{
    printf("  %-2s  | %-29s \n", "No", "Name");
    for (int i = 0; i < n; i++)
    {
        if ((allContacts + i)->status == 1)
        {
            printContact((i + 1), (allContacts + i));
        }
    }
}

void searchContactHandle(int *count, Contact *allContacts, char inputSearchName[20])
{
    Line();
    printf("  %-2s  | %-29s \n", "No", "Name");
    for (int i = 0; i < *count; i++)
    {
        if (strcmp((allContacts + i)->firstName, inputSearchName) == 0 || strcmp((allContacts + i)->lastName, inputSearchName) == 0)
        {
            printContact((i + 1), (allContacts + i));
        }
    }
    Line();
}

void DeleteContactHandle(int no, Contact *allContacts, int *count)
{
    int n = *count;
    for (int i = no; i < *count; i++)
    {
        *(allContacts + i) = *(allContacts + i + 1);
    }
    n--;
    *count = n;
}

int readContactsFromFile(Contact *allContacts, int *count, const char *fileName)
{
    FILE *f;
    f = fopen(fileName, "rb");
    if (f == NULL)
    {
        return 0;
    }
    int i;
    for (i = 0; !feof(f); i++)
    {
        fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d\n", &(allContacts + i)->firstName, &(allContacts + i)->middleName, &(allContacts + i)->lastName, &(allContacts + i)->company, &(allContacts + i)->phone, &(allContacts + i)->email, &(allContacts + i)->address, &(allContacts + i)->birthday, &(allContacts + i)->website, &(allContacts + i)->note, &(allContacts + i)->status);
    }
    *count = i;
    fclose(f);
    return 1;
}

int writeContactsToFile(Contact *allContacts, int count, const char *fileName)
{
    FILE *f;
    f = fopen(fileName, "wb");
    if (f == NULL)
    {
        return 0;
    }
    int i;
    for (i = 0; i < count; i++)
    {
        fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d\n", allContacts[i].firstName, allContacts[i].middleName, allContacts[i].lastName, allContacts[i].company, allContacts[i].phone, allContacts[i].email, allContacts[i].address, allContacts[i].birthday, allContacts[i].website, allContacts[i].note, allContacts[i].status);
    }
    fclose(f);
    return 1;
}

void UpdatingSuccess()
{
    Line();
    printf(" Updating.. Success!\n");
    Line();
    PressEnterToContinue();
}

void getString(char *str, int length)
{
    fflush(stdin);
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    fflush(stdin);
}

void Line()
{
    printf("==================================================\n");
}

void PressEnterToContinue()
{
    printf(" Press Enter To Continue..");
    fflush(stdin);
    getchar();
}

void deletingSuccess()
{
    Line();
    printf(" Deleting.. Success!\n");
    Line();
    PressEnterToContinue();
}

void detailMenuHandle(int no, int *count, Contact *allContacts)
{
    int c = *count;
    no -= 1;
    contactsDetailsUI(no, allContacts);
    int detailChoice = DetailMenuUI();
    switch (detailChoice)
    {
    case 1:
        AddToFavouritesHandle(no, allContacts, &c);
        writeContactsToFile(allContacts, c, "contacts.csv");
        break;
    case 2:
        switch (UpdateContactMenu())
        {
        case 1:
            printf(" First Name: ");
            UpdateContactFNameHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 2:
            printf(" Middle Name: ");
            UpdateContactMNameHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 3:
            printf(" Last Name: ");
            UpdateContactLNameHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 4:
            printf(" Company: ");
            UpdateContactCompanyHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 5:
            printf(" Phone: ");
            UpdateContactPhoneHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 6:
            printf(" Email: ");
            UpdateContactEmailHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 7:
            printf(" Address: ");
            UpdateContactAddressHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 8:
            printf(" Birthday: ");
            UpdateContactBirthdayHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 9:
            printf(" Website: ");
            UpdateContactWebsiteHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        case 10:
            printf(" Note: ");
            UpdateContactNoteHandle(no, allContacts, &c);
            UpdatingSuccess();
            break;
        default:
            chooseAlert(1, 10);
            break;
        }
        break;
    case 3:
        DeleteContactHandle(no, allContacts, &c);
        writeContactsToFile(allContacts, c, "contacts.csv");
        deletingSuccess();
        break;
    case 4:
        printf("\n Updating..\n");
        PressEnterToContinue();
        break;
    case 5:
        break;
    default:
        chooseAlert(1, 5);
        break;
    }
}