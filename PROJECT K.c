#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_USERS 100

struct User
{
    char name[50];
    char password[50];
    int age;
    char district[50];
    char city[50];
    int id;
    double fundAmount;
};

void registerUser(struct User users[], int *userCount)
{
    if (*userCount < MAX_USERS)
    {
        struct User newUser;
        printf("Registration\n");
        printf("Name: ");
        scanf("%s", newUser.name);
        printf("Password: ");
        scanf("%s", newUser.password);
        printf("Age: ");
        scanf("%d", &newUser.age);
        printf("District: ");
        scanf("%s", newUser.district);
        printf("City: ");
        scanf("%s", newUser.city);
        printf("ID(Please put integer id name given by Govt. : ");
        scanf("%d", &newUser.id);
        newUser.fundAmount = 0.0;

        users[*userCount] = newUser;
        (*userCount)++;


        FILE *file = fopen("users.txt", "a");
        fprintf(file, "%s %s %d %s %s %d %lf\n", newUser.name, newUser.password, newUser.age, newUser.district, newUser.city, newUser.id, newUser.fundAmount);
        fclose(file);

        printf("Registration successful.\n");
    }
    else
    {
        printf("User limit reached. Cannot register more users.\n");
    }
}

int findUserByName(struct User users[], int userCount, const char *name, const char *pass, const char *city)
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].name, name) == 0)
        {
            if(strcmp(users[i].password, pass) == 0)
            {
                if(strcmp(users[i].city, city) == 0)
                {
                    return i;
                }

                else if( i < userCount)
                {
                    continue;
                }

                else
                {
                    return -3;
                }
            }

            else if( i < userCount)
            {
                continue;
            }

            else
            {
                return -2;
            }
        }
    }

    return -1;
}

int main()
{
    struct User users[MAX_USERS];
    int userCount = 0;

    FILE *file = fopen("users.txt", "r");
    if (file)
    {
        while (!feof(file) && userCount < MAX_USERS)
        {
            struct User user;
            if (fscanf(file, "%s %s %d %s %s %d %lf", user.name, user.password, &user.age, user.district, user.city, &user.id, &user.fundAmount) == 7)
            {
                users[userCount] = user;
                userCount++;
            }
        }
        fclose(file);
    }

    int choose;
    int choice;
    int css;

    char name[50];
    char pass[50];
    char city[50];

    int id1 = 11022007;
    int id2 = 11022004;
    int id3 = 11022041;

    int pin = 4741;

    int ide;
    int pins;
    double tfnd = 0;
    double fnd = 0;



    while (1)
    {
        printf("Welcome to fund and relief distribution system. Why are you here for?\n1.I am Admin\n2.I am here to collect fund\n3.What is this about\n4.Sorry I am in the wrong place\nEnter your choice : ");
        scanf("%d", &choose);

        switch(choose)
        {
            case 1:
            {
                char text[] = "\n\n         Hello and welcome to our online platform for fund and relief distribution! We're delighted to have you join us, especially as a government employee contributing to this vital project. Your presence in the admin panel is crucial in ensuring the efficient and effective allocation of resources to those in need. Thank you for your dedication and commitment to this cause. Together, we can make a significant impact in our community and beyond. If you have any questions or need assistance, please don't hesitate to reach out. Once again, welcome to our platform, and let's work together to make a difference.";

                int maxLineWidth = 100;

                int textLength = strlen(text);
                int startPos = 0;
                int endPos = 0;

                while (startPos < textLength)
                {
                    endPos = startPos + maxLineWidth;

                    if (endPos > textLength)
                        endPos = textLength;

                        printf("         %.*s\n", endPos - startPos, &text[startPos]);

                        startPos = endPos;
                }

                printf("\n\n    Enter your unique id : ");
                scanf("%d", &ide);

                if(ide == id1 || ide == id2 || ide == id3)
                {
                    printf("\n    We have found your id. Please enter your password :");
                    scanf("%d", &pins);

                    if(pins == pin)
                    {
                        printf("\n    Welcome admin, have a nice day!");
                        printf("\n\n    1.Add new fund amount\n    2.Check current fund\n    3.Exit\n    Enter your choice : ");
                        scanf("%d", &css);

                        switch(css)
                        {
                            case 1:
                            {
                                struct User uses[MAX_USERS];
                                printf("\n\n    Add fund amount : ");
                                scanf("%lf\n\n", &tfnd);

                                fnd = tfnd/(double)userCount;

                                for(int x = 0; x < userCount; x++)
                                {
                                    if(uses[x].fundAmount < uses[x].fundAmount + fnd)
                                    {
                                        uses[x].fundAmount = uses[x].fundAmount + fnd;

                                        users[x].fundAmount = uses[x].fundAmount;

                                        FILE *file = fopen("users.txt", "a");
                                        fprintf(file, "%lf\n", uses->fundAmount);
                                        fclose(file);
                                    }
                                }
                                break;
                            }

                            case 2:
                                printf("\n\n    Current fund amount is : %lf\n\n", fnd);
                                break;

                            case 3:
                                return 0;

                            default:
                                printf("Invalid choice. Please try again.\n\n");
                        }
                    }
                }
                break;
            }
            case 2:
            {
                printf("\n1. Register\n2. Login\n3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        registerUser(users, &userCount);
                        break;

                    case 2:
                        printf("Login\n");
                        printf("Name: ");
                        scanf("%s", name);

                        printf("Password: ");
                        scanf("%s", pass);

                        printf("City Name: ");
                        scanf("%s", city);

                        int userIndex = findUserByName(users, userCount, name, pass, city);

                        if (userIndex > -1)
                        {
                            printf("Welcome, %s!\n", users[userIndex].name);
                            if (users[userIndex].fundAmount > 0.0)
                            {
                                printf("You were given %.2lf from the city fund.\n", users[userIndex].fundAmount);
                            }
                            else
                            {
                                printf("You have not received any money from the city fund.\n");
                            }
                        }

                        else if(userIndex == -3)
                        {
                            printf("This city doesn't have this user. Please check your city or register if you haven't yet. Thank you.\n");
                        }

                        else if(userIndex == -2)
                        {
                            printf("You have entered wrong password. Please enter the correct one or register if you haven't yet. Thank you.\n");
                        }

                        else if(userIndex == -1)
                        {
                            printf("User not found. Please register.\n");
                        }
                        break;

                    case 3:
                        file = fopen("users.txt", "w");
                        for (int i = 0; i < userCount; i++)
                        {
                            fprintf(file, "%s %s %d %s %s %d %lf\n", users[i].name, users[i].password, users[i].age, users[i].district, users[i].city, users[i].id, users[i].fundAmount);
                        }
                        fclose(file);
                        return 0;

                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            }

            case 3:
            {
                 char text[] = "\n\n         Welcome to our Online Fund and Relief Distribution Platform!"
"We are delighted to have you here, where we aim to make a positive impact on those in need. Whether you're seeking assistance or looking to contribute, our platform is designed to connect those who care with those who require support."
"If you're new to our platform, you can register by providing your name, age, address, and other necessary details. We value your trust and promise to handle your information with the utmost care and confidentiality."
"If you've already registered, welcome back! Simply log in to access the resources and support you need."
"Thank you for being a part of this compassionate community. Together, we can make a difference in the lives of those facing challenges. If you have any questions or need assistance, please don't hesitate to reach out. Let's work together to create a better tomorrow.\n\n";

                int maxLineWidth = 100;

                int textLength = strlen(text);
                int startPos = 0;
                int endPos = 0;

                while (startPos < textLength)
                {
                    endPos = startPos + maxLineWidth;

                    if (endPos > textLength)
                        endPos = textLength;

                        printf("         %.*s\n", endPos - startPos, &text[startPos]);

                        startPos = endPos;
                }
                break;
            }

            case 4:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
