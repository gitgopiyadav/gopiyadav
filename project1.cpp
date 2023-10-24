#include <bits/stdc++.h>
using namespace std;

class user
{
private:
    string username, password;

public:
    user(string name, string pass)
    {
        username = name;
        password = pass;
    }
    string getusername()
    {
        return username;
    }
    string getpassword()
    {
        return password;
    }
};
class userManager
{
private:
    vector<user> users; // create object of vector
public:
    void RegisterUser()
    {
        string username, password;
        cout << "\t\tEnter User name : ";
        cin >> username;
        cout << "\t\tEnter Password : ";
        cin >> password;

        user newUser(username, password);
        users.push_back(newUser);
        cout << "\t\t User Register Successfully....." << endl;
    }
    bool LoginUser(string name, string pass)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getusername() == name && users[i].getpassword() == pass)
            {
                cout << "\t\tLogin Successfully.... " << endl;
                return true;
            }
        }
        cout << "\t\tInvalid User Name or Password... " << endl;
        return false;
    }
    void showUser()
    {
        cout << "\t\t---Users List---" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << "\t\t" << users[i].getusername() << endl;
        }
    }

    void searchUser(string username)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getusername() == username)
            {
                cout << "\t\t User Found" << endl;
            }
                }
    }

    void deleteUser(string username)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getusername() == username)
            {
                users.erase(users.begin() + i);
                cout << "\t\tUser Remove Successfully...." << endl;
            }
            
        }
    }
};

int main()
{
    userManager usermanage;

    int op;
    char choice;

    do
    {
        system("cls");
        cout << "\n\n\t\t1. Register User " << endl;
        cout << "\t\t2. Login " << endl;
        cout << "\t\t3. Show User list " << endl;
        cout << "\t\t4. Search User " << endl;
        cout << "\t\t5. Delete User " << endl;
        cout << "\t\t6. Exit " << endl;
        cout << "\t\tEnter Your Choice : ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            usermanage.RegisterUser();
            break;
        }
        case 2:
        {
            string username, password;
            cout << "\t\tEnter Username :";
            cin >> username;
            cout << "\t\tEnter Password :";
            cin >> password;
            usermanage.LoginUser(username, password);
            break;
        }
        case 3:
        {
            usermanage.showUser();
            break;
        }
        case 4:
        {
            string username;
            cout << "\t\tEnter User Name :";
            cin >> username;
            usermanage.searchUser(username);
            break;
        }
        case 5:
        {
            string username;
            cout << "\t\tEnter User Name :";
            cin >> username;
            usermanage.deleteUser(username);
            break;
        }
        case 6:
            exit(1);
        }
        cout << "\t\tDo You Want to Continue [Yes/No] ? :";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
