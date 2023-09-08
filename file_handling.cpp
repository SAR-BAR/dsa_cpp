
#include <iostream>
#include <fstream>
using namespace std;
# define M 70

//Struct definition to store info of students
struct Student
{
    string Name ;
    int Roll;
    int div ;
    string add ;
};

class C{

     Student studInfo;
public:
    void createFile(char name []);
    void addRecords(char name[]);
    void displayRecords(char name[]);
    void searchRecord(char name[]);
    void deleteRecord(char name[]);
    void modifyRecord(char name[]);

};


//Function to Create a file if it does not exist already
void C :: createFile(char name[] ){
    ifstream fin;
    fin.open(name);
    if(fin){
        cout<<"File already Created!\n";
    }else {
        ofstream fout;
        fout.open(name, ios::app);
        cout<<" File Created Successfully!\n";
    }
    fin.close();
}


//Function to add Data into file
void C :: addRecords(char name[]){
    ofstream fout;
    fout.open(name, ios::app);

    //Taking input from user
    cout<<"Enter Name: ";
    cin>>studInfo.Name;
    cout<<"Enter RollNo: ";
    cin>>studInfo.Roll;
    cout<<"Enter Division: ";
    cin>>studInfo.div;
    cout<<"Enter address ";
    cin >> studInfo.add ;

    fout.write((char*)&studInfo, sizeof(studInfo));
    fout.close();

}


//Function to display records from file to console
void C :: displayRecords(char name[]){
     ifstream fin;
    fin.open(name);
    fin.read((char*)&studInfo, sizeof(studInfo));
    cout<<"Name\t\tRoll\t\tDivision\t\tAddress\n";
    while(!fin.eof()){
         cout<<studInfo.Name<<"\t\t"<<studInfo.Roll<<"\t\t"<<studInfo.div<<"\t\t  "<<studInfo.add<<"\n";
        fin.read((char*)&studInfo, sizeof(studInfo));

    }
    fin.close();

}


//Function to Search for a record in file
void C :: searchRecord(char name[]){
     int searchRoll;

    ifstream fin;
    fin.open(name);

    fin.read((char*)&studInfo, sizeof(studInfo));

    cout<<"Enter Roll Number you want to search: ";
    cin>>searchRoll;

    int flag = 0;

    while(!fin.eof()){
        if(studInfo.Roll == searchRoll){
            cout<<"\nData found!!\n";
            cout<<"Name\t\tRollNo\t\tDivision\t\tAddress\n";
            cout<<studInfo.Name<<"\t\t"<<studInfo.Roll<<"\t\t"<<studInfo.div<<"\t\t"<<studInfo.add<<"\n\n";
            flag = 1;
            break;

        }else {
            fin.read((char*)&studInfo, sizeof(studInfo));

        }
    }
    

    if(flag != 1){
          cout<<"Data is NOT PRESENT in the file!\n";

    }
    fin.close();
}


//Funtion to delete a record from the records already exist in original file
void C :: deleteRecord(char name[]){
     int delRoll;
    ofstream fout;
    fout.open("Copy.dat", ios::app);

    ifstream fin;
    fin.open(name);

    fin.read((char*)&studInfo, sizeof(studInfo));

    cout<<"Enter Roll Number to be Deleted: ";
    cin>>delRoll;

    while(!fin.eof()){
         if(delRoll != studInfo.Roll){
            fout.write((char*)&studInfo, sizeof(studInfo));
            fin.read((char*)&studInfo, sizeof(studInfo));

         }
        else{
             cout<<"\nFollowing Record Deleted Successfully!\n";
            cout<<"Name\t\tRoll\t\tPercentage\n";
            cout<<studInfo.Name<<"\t\t"<<studInfo.Roll<<"\t\t"<<studInfo.div<<"\t\t"<<studInfo.add<<"\n";
            fin.read((char*)&studInfo, sizeof(studInfo));
        }
    }
    
    fin.close();
    fout.close();

    remove(name);
    rename("Copy.dat", name);

    cout<<"\nDataBase after Deleting Record is as Follows.\n";
    displayRecords(name);

}


//Function to Modify an Existing Record
void C :: modifyRecord(char name[]){
      int modifyRoll;
    ifstream fin;
    fin.open(name);

    ofstream fout;
    fout.open("ModiFile.dat");

    fin.read((char*)&studInfo, sizeof(studInfo));

    cout<<"Enter Roll Number of Student whose Data is to be Modified: ";
    cin>>modifyRoll;

    while(!fin.eof())
    {
        if(studInfo.Roll != modifyRoll)
        {
            fout.write((char*)&studInfo, sizeof(studInfo));
            fin.read((char*)&studInfo, sizeof(studInfo));
        }
        else
        {
            int modifyMore;
            do
            {
                int choice;
                cout<<"Record to modify Found!\n";
                cout<<"Which field to modify?\n1.Name\n2.Division\n3.Address\n";
                cin>>choice;

                if(choice == 1)
                {
                    cout<<"Enter Modified Name: ";
                    cin>>studInfo.Name;
                }
                else if(choice == 2)
                {
                    cout<<"Enter Modified Division: ";
                    cin>>studInfo.div;
                }
                else if(choice == 3)
                {
                    cout<<"Enter modified address ";
                    cin >> studInfo.add ;
                    
                }

                cout<<"\nDo you want to Modify More Fields? 1)Yes 2)No: ";
                cin>>modifyMore;
            } while (modifyMore == 1);
            fout.write((char*)&studInfo, sizeof(studInfo));
            cout<<"\nRecord Modified Successfully!\n";
            fin.read((char*)&studInfo, sizeof(studInfo));
        }
    }

    fin.close();
    fout.close();

    remove(name);
    rename("ModiFile.dat", name);

    cout<<"\nDataBase after Modifying Record is as Follows.\n";
    displayRecords(name);
    

}


int main()
{
    char name[M];
    C c;
    cout<<"Enter name for your file ";
    cin >> name ;
    cout<<"----------------------FILE HANDLING----------------------\n";
    while(true)
    {
        int choice;
        cout<<"\nWhich operation to perform?\n1)Add Records\n2)Display Records\n3)Search Record\n4)Delete Record\n5)Modify Record\n6)Exit\n ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"\n";
            c.addRecords(name);
            cout<<"\n";
        }
        else if(choice == 2)
        {
            cout<<"\n";
            c.displayRecords(name);
            cout<<"\n";
        }
        else if(choice == 3)
        {
            cout<<"\n";
            c.searchRecord(name);
            cout<<"\n";
        }
        else if(choice == 4)
        {
            cout<<"\n";
            c.deleteRecord(name);
            cout<<"\n";
        }
        else if(choice == 5)
        {
            cout<<"\n";
            c.modifyRecord(name);
            cout<<"\n";
        }
        else if(choice == 6)
        {
            break;
        }
        else
        {
            cout<<"Please Enter A valid Choice!\n";
        }
    }
    
    cout<<"Thank You!\n";

    return 0;
}