#include<iostream>
#include<string>
using namespace std;

struct Employee{//struct is used to define user-defined data type
    int emp_id;
    string emp_name;
    string designation;
    string department;
    float salary;
};

   void getEmployeeInfo(Employee &e){
    cout<<"\nEnter Employee id: ";
    cin>>e.emp_id;
    cin.ignore();

    cout<<"Enter Employee Name: ";
    getline(cin,e.emp_name);//getline() reads the entire line,including spaces.

    cout<<"Enter Designation: ";
    getline(cin,e.designation);
    
    cout<<"Enter Department: ";
    getline(cin,e.department);

    cout<<"Enter Salary: ";
    cin>>e.salary;
    cin.ignore();
}
void displayEmployeeInfo(const Employee &e){
  cout<<"\nEmployee Id: "<<e.emp_id;
  cout<<"\nName: "<<e.emp_name;
  cout<<"\nDesignation: "<<e.designation;
  cout<<"\nDepartment: "<< e.department;
  cout<<"\nSalary: "<<e.salary;
  cout<<"\n-------------------------------\n";
}

int countSalesEmployee(Employee emp[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(emp[i].department == "sale" || emp[i].department == "Sale")
        count++;
    }
    return count;
}

// int main(){
//   Employee emp[2];
// //input employee details
// cout<<"Enter information for 2 Employeea:\n";
// for(int i=0;i<2;i++){
//     getEmployeeInfo(emp[i]);
// }
// //display employee details
// cout<<"\n--Displaying Employee Information--\n";
// for(int i=0;i<2;i++){
//     displayEmployeeInfo(emp[i]);
// }

// int saleCount = countSalesEmployee(emp,2);
// cout<<"\nNumber of employees in 'Sale' department = "<< saleCount;
// }
//struct is a user-defined type
//e is a reference to an Employee object
//& ampersand -pass by reference`,do not copy object,work directly on the original object. 
//passing by value = photocopy
//passing by reference = original file changes
int main(){
    const int size=20;
    Employee emp[size];
    int count=0;
    int choice;

    do{
        cout<<"\n----------------------------";
        cout<<"\n     Employee Menu";
        cout<<"\n----------------------------";
        cout<<"\n1. Add Employee";
        cout<<"\n2. Display All Employee";
        cout<<"\n3. Count Sales department Employee";
        cout<<"\n4. Exit";
        cout<<"\n Enter your choice: ";
        cin>>choice;
        
        switch(choice){
            case 1:
            if(count<size){
             cout<<"\n--Enter Employee "<<count+1<<" Details--\n";
             getEmployeeInfo(emp[count]);
             count++;
            }else{
                cout<<"\nEmployee list is full";
            }
            break;

            case 2:
            if(count==0){
                cout<<"\nNo employee data found";
            }else{
                cout<<"\n---All Employee details--";
                for(int i=0;i<count;i++){
                    displayEmployeeInfo(emp[i]);
                }
            }
               break;
            case 3:
            cout<<"\nEmployee in 'Sale' department = "
            <<countSalesEmployee(emp,count)<<"\n";
            break;

            case 4:
            cout<<"\nExiting Program...\n";
            break;

            default:
            cout<<"\nInvalide option! Try agin\n";
        }   
    }
    while(choice!=4);
    return 0;
}