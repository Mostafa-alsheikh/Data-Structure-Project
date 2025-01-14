#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "classes.h"
using namespace std;

int main()
{
    int working = 1;
    supplierTree ST;
    sparePartTree SPT;
    stack S;
    queue Q;
    while (working)
    {
        cout << "Press any key..." << "\n";
        getch();
        system("cls");
        cout << "Welcome to the Inventory" << "\n";
        getch();
        cout << "\n" << "Please Choose an Option" << "\n";
        cout << "1. Supplier" << "\n";
        cout << "2. Spare Part" << "\n";
        cout << "3. History" << "\n";
        cout << "4. Close Program" << "\n";
        int choice1 = 0;
        cin >> choice1;
        system("cls");
        switch (choice1)
        {
            case 1:
            {
                int working1 = 1;
                while (working1)
                {
                    system("cls");
                    cout << "What do you want to do?" << "\n";
                    cout << "1. Add Supplier  " << "\n";
                    cout << "2. Delete Supplier " << "\n";
                    cout << "3. Display Supplier " << "\n";
                    cout << "4. modify Supplier " << "\n";
                    cout << "5. search Supplier " << "\n";
                    cout << "6. Add part to the Supplier " << "\n";
                    cout << "7. Back " << "\n";
                    int choice2 = 0;
                    cin >> choice2;
                    switch (choice2)
                    {
                        case 1:
                        {
                            ST.insert();
                            Q.enqueue("User procced a supplier");
                            S.push("User added a supplier");
                            break;
                        }
                        case 2:
                        {
                            int del;
                            cout << "Which Supplier do you want to delete?(Enter an integer)";
                            cin >> del;
                            ST.remove(del);
                            S.push("User deleted a supplier");
                            break;
                        }
                        case 3:
                        {
                            int dis;
                            cout << "Which Supplier do you want to display?(Enter an integer)";
                            cin >> dis;
                            ST.display(dis);
                            S.push("User displayed a supplier");
                            getch();
                            break;
                        }
                        case 4:
                        {
                            int mod;
                            cout << "Which Supplier do you want to modify?(Enter an integer)";
                            cin >> mod;
                            ST.modify(mod);
                            Q.enqueue("User updated a supplier");
                            S.push("User modified a supplier");
                            getch();
                            break;
                        }
                        case 5:
                        {
                            int ser;
                            cout << "Which Supplier do you want to search?(Enter an integer)";
                            cin >> ser;
                            ST.search(ser);
                            S.push("User searched a supplier");
                            getch();
                            break;
                        }
                        case 6:
                        {
                            int supplierCode, partNumber;
                            cout << "Enter Supplier Code: ";
                            cin >> supplierCode;
                            cout << "Enter Part Number: ";
                            cin >> partNumber;

                            supplierNode* supplierNodePtr = ST.searchNode(supplierCode);
                            sparePartNode* sparePartNodePtr = SPT.searchNode(partNumber);

                            if (supplierNodePtr != nullptr && sparePartNodePtr != nullptr)
                            {
                                supplierNodePtr->addSparePart(sparePartNodePtr->getdata());
                                cout << "Spare Part added to the Supplier successfully." << endl;
                            }
                            else
                            {
                                cout << "Supplier or Spare Part not found." << endl;
                            }
                        }
                        case 7:
                        {
                            working1 = 0;
                            break;
                        }
                        default:
                            cout << "Invalid Option, Try Again!" << "\n";
                    }
                }
                break;
            }
            case 2:
            {
                int working2 = 1;
                while (working2)
                {
                    system("cls");
                    cout << "What do you want to do?" << "\n";
                    cout << "1. Add Spare Part  " << "\n";
                    cout << "2. Delete Spare Part " << "\n";
                    cout << "3. Display Spare Part" << "\n";
                    cout << "4. modify Spare Part" << "\n";
                    cout << "5. search Spare Part" << "\n";
                    cout << "6. Back " << "\n";
                    int choice3 = 0;
                    cin >> choice3;
                    switch (choice3)
                    {
                        case 1:
                        {
                            SPT.insert();
                            Q.enqueue("User procced a Spare Part");
                            S.push("User added a Spare Part");
                            break;
                        }
                        case 2:
                        {
                            int del;
                            cout << "Which Spare Part do you want to delete?(Enter an integer)";
                            cin >> del;
                            SPT.remove(del);
                            S.push("User deleted a Spare Part");
                            getch();
                            break;
                        }
                        case 3:
                        {
                            int dis;
                            cout << "Which Spare Part do you want to display?(Enter an integer)";
                            cin >> dis;
                            SPT.display(dis);
                            S.push("User dispalyed a Spare Part");
                            getch();
                            break;
                        }
                        case 4:
                        {
                            int mod;
                            cout << "Which Spare Part do you want to modify?(Enter an integer)";
                            cin >> mod;
                            SPT.modify(mod);
                            S.push("User modified a Spare Part");
                            Q.enqueue("User updated a Spare Part");
                            getch();
                            break;
                        }
                        case 5:
                        {
                            int ser;
                            cout << "Which Spare Part do you want to search?(Enter an integer)";
                            cin >> ser;
                            SPT.search(ser);
                            getch();
                            break;
                        }
                        case 6:
                        {
                            working2 = 0;
                            break;
                        }
                        default:
                            cout << "Invalid Option, Try Again!" << "\n";
                    }
                }
                break;
            }
            case 3:
            {
                int working3 = 1;
                while (working3)
                {
                    system("cls");
                    cout << "What do you want to do?" << "\n";
                    cout << "1. Stack " << "\n";
                    cout << "2. Queue " << "\n";
                    cout << "3. Back " << "\n";
                    int choice4 = 0;
                    cin >> choice4;
                    switch (choice4)
                    {
                        case 1:
                        {
                            S.display();
                            break;
                        }
                        case 2:
                        {
                            Q.display();
                            break;
                        }

                        case 3:
                        {
                            working3 = 0;
                            break;
                        }
                        default:
                            cout << "Invalid Option, Try Again!" << "\n";
                    }
                }
                break;
            }
            case 4:
            {
                working = 0;
                break;
            }
            default:
                cout << "Invalid Option, Try Again!" << "\n";
                continue;
        }
    }
    return 0;
}
