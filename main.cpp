//takes array and return sum of all even number in array
/*
#include<bits/stdc++.h>
using namespace std;
int evennumbers( int arr[],int arr_size){
    int sum=0;
        for(int j=0;j<arr_size;j++){
            if(arr[j]%2==0){
                sum+=arr[j];

            }

        }
    return sum;
}
int main(){
    int arr_size;
    cout<<"enter array size";
    cin>>arr_size;
    int arr[arr_size];
    for(int j=0;j<arr_size;j++){
        cin>>arr[j];
    }
     int even_sum =evennumbers(arr,arr_size);
    cout<<even_sum;
 return 0;
}


//function takes two arrays of integer and returns a new array that contain only the common elements in both two arrays
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void same_element(int arr1[],int arr2[],int arr1_size,int arr2_size,int common[],int &var){
     var=0;
    for(int i=0;i<arr1_size;i++){
        for(int j=0;j<arr2_size;j++){
            if(arr1[i]==arr2[j]){
                common[var]=arr1[i];
                var++;





            }
        }
    }

}
int main(){
     int arr1_size, arr2_size;
     cout<<"enter the arrays size";
     cin>>arr1_size>>arr2_size;
    int arr1[arr1_size];
    cout<<"enter array 1"<<'\n';
     for(int i=0;i<arr1_size;i++){
           cin>>arr1[i];}
    int arr2[arr2_size];
     cout<<"enter array 2"<<'\n';
     for(int j=0;j<arr2_size;j++){
         cin>>arr2[j];
     }
     int var;
     int common[arr1_size<arr2_size?arr1_size:arr2_size];
     same_element(arr1,arr2,arr1_size,arr2_size,common,var);
     cout<<"common elements"<<'\n';
     for(int i=0;i<var;i++){
         cout<<common[i]<<'\n';
     }
 return 0;
}
*/
//swap function using pointer
/*
#include<bits/stdc++.h>
using namespace std;
void swap(int*a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a;
    int b;
    cout<<"enter the two numbers"<<'\n';
    cin>>a>>b;
    swap(&a,&b);
    cout<<"swapped numbers are"<<'\n';
    cout<<a<<'\n'<<b;
 return 0;
}
*/
//struct of student with name,age,gpa return student with highest gpa
/*
#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    double GPA;
};

void highest_GPA(Student* studentarray, int n) {
    int index_found = 0;

    for (int i = 1; i < n; i++) {
        if (studentarray[i].GPA > studentarray[index_found].GPA) {
            index_found = i;
        }
    }

    cout << "Student with the highest GPA:" << endl;
    cout << "Name: " << studentarray[index_found].name << endl;
    cout << "Age: " << studentarray[index_found].age << endl;
    cout << "GPA: " << studentarray[index_found].GPA << endl;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student* studentarray = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter student name: ";
        cin >> studentarray[i].name;

        cout << "Enter student age: ";
        cin >> studentarray[i].age;

        cout << "Enter student GPA: ";
        cin >> studentarray[i].GPA;
    }

    highest_GPA(studentarray, n);

    delete[] studentarray;
    return 0;
}
*/
//program allocate dynamic array of integer based on the input user and fill it with random numbers between 1 &100
/*
#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main(){
    srand(time(0));
    int size;
    int *num;
    cout<<"enter array size"<<endl;
    cin>>size;
    num =new int [size];
    cout<<"random array"<<endl;
    for(int i=0;i<size;i++){
        num[i]=1+rand()%10;
        cout<<num[i]<<" ";
    }
 return 0;
}
 */
/*
//Write a program that uses a 2D array to represent a tic-tac-toe board. Allow two players to take turns entering their moves, and check for win conditions after each move.
#include <iostream>
using namespace std;

const int game_size= 3;

char board[game_size][game_size];

void initializeBoard() {//intialize the board of game to empty spaces
    for (int i = 0; i < game_size; i++) {
        for (int j = 0; j < game_size; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {//function which cout the board with empty spaces
    for (int i = 0; i < game_size; i++) {
        for (int j = 0; j < game_size; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int row, int col) {//checks row and column are within the board boundaries and if the corresponding cell is empty.
    if (row < 0 || row >=game_size || col < 0 || col >= game_size) {
        return false;
    }

    if (board[row][col] != ' ') {
        return false;
    }

    return true;
}

bool isWin(char player) {
    // Check row
    for (int i = 0; i < game_size; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check col
    for (int j = 0; j < game_size; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diag
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < game_size; i++) {
        for (int j = 0; j < game_size; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    char currentPlayer = 'X';

    while (true) {
        displayBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move  ";
        cin >> row >> col;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;

            if (isWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    initializeBoard();
    playGame();

    return 0;
}
*/
// function takes an array of strings and sorts them in alphabetical order using pointers.
/*
#include<bits/stdc++.h>
#include <string>
using namespace std;

void sortStrings(string* strings, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strings[i] > strings[j]) {
                string temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter the number of strings: ";
    cin >> size;

    string* strings = new string[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter string ";
        cin >> strings[i];
    }

    sortStrings(strings, size);

    cout << "Sorted strings:" << endl;
    for (int i = 0; i < size; i++) {
        cout << strings[i] << endl;
    }

    delete[] strings;
    return 0;
}
*/
//Write a program that uses pointers to find the largest element in an array of doubles.
/*
#include<bits/stdc++.h>
using namespace std;
double largest_double(double *arr,int size){
    double largest=*arr;
    for(int i=0;i<size;i++){
        if(*(arr+i)>largest){
            largest=*(arr+i);
        }
    }
    return largest;


}
int main(){
    int size;
    cout<<"enter array size"<<'\n';
    cin>>size;
    double* arr=new double [size];
    cout<<"enter array"<<'\n';
    for(int i=0;i<size;i++){
        cin>>*(arr+i);
    }
     double large=largest_double(arr,size);
    cout<<"largest double is"<<'\n'<<large;
 return 0;
}
*/
//Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
//
//A string is represented by an array if the array elements concatenated in order forms the string.//leet code.
/*
#include<bits/stdc++.h>
using namespace std;
bool are_equal_strings(string*word1,int size_1,string*word2,int size_2){
    string s1;
    string s2;
    for(int i=0;i<size_1;i++){
        s1+=word1[i];

    }
    for(int i=0;i<size_2;i++){
        s2+=word2[i];
    }



    return s1==s2;
}
int main(){
   int word1_size,word2_size;
   cout<<"enter first string size"<<'\n';
   cin>>word1_size;
    cout<<"enter second string size"<<'\n';
    cin>>word2_size;
    string*word1=new string[word1_size];
    string*word2=new string[word2_size];
    cout<<"enter the first string"<<'\n';
    for(int i=0;i<word1_size;i++){
        cin>>word1[i];
    }
    cout<<"enter the second string"<<'\n';
    for(int i=0;i<word2_size;i++){
        cin>>word2[i];
    }
    bool equal= are_equal_strings(word1,word1_size,word2,word2_size);
    cout<<(equal?"true":"false")<<'\n';
    delete[]word1;
    delete[]word2;
 return 0;
}
*/
//struct that takes the students data and print it
/*
#include<bits/stdc++.h>
using namespace std;
struct person {
    string name;
    string email;
    int age;
};
void input(person*personarray,int n){
    cout<<"enter the data"<<'\n';
    for(int i=0;i<n;i++){
        cin>>personarray[i].name>>personarray[i].email>>personarray[i].age;
    }
    cout<<"the students data is "<<'\n';
    for(int i=0;i<n;i++){
        cout<<personarray[i].name<<'\n'<<personarray[i].email<<'\n'<<personarray[i].age<<'\n';
    }
}

int main(){
    int n;

    cout<<"enter the number of students"<<'\n';
    cin>>n;
    person*personarray=new person[n];
    input(personarray,n);
    delete[]personarray;
 return 0;
}
*/
/*
 * //struct to a rectangle to calculate the area and premieter
 #include<bits/stdc++.h>
 using namespace std;
 struct rectangle{
     float length;
     float width;
 };
 void area_premeiter(rectangle*rectanglearray,int n){
     for(int i=0;i<n;i++){
         cout<<"enter the rectangles lengths "<<'\n';
         cin>>rectanglearray[i].length;
         cout<<"enter the rectangles widths "<<'\n';
         cin>>rectanglearray[i].width;



     }
     cout<<"the areas of rectangles are"<<'\n';
     for(int i=0;i<n;i++){
         cout<<"area of rectangle"<<i+1<<'\n';
         cout<<rectanglearray[i].length*rectanglearray[i].width<<'\n';
     }
     cout <<"the premieters of rectangles are"<<'\n';
     for(int i=0;i<n;i++){
         cout<<"the premieter of rectangle"<<i+1<<'\n';
         cout<<2*(rectanglearray[i].length+rectanglearray[i].width)<<'\n';

     }
 }
 int main(){
     int n;
     cout<<"enter the number of rectangles"<<'\n';
     cin>>n;
     rectangle*rectanglearray=new rectangle[n];
     area_premeiter(rectanglearray,n);
     delete[]rectanglearray;
  return 0;
 }
 */
 //or without array
/*
 #include<bits/stdc++.h>
 using namespace std;
 struct rectangle{
     float length;
     float width;
 };
 int main(){
     rectangle r;
     cout<<"enter the length of rectangle "<<'\n';
     cin>>r.length;
     cout<<"enter the width of rectangle"<<'\n';
     cin>>r.width;
     float area=r.length*r.width;
     float premieter=(r.length+r.width)*2;
     cout<<"area is "<<area<<'\n';
     cout<<"premieter is"<<premieter<<'\n';
  return 0;
 }
*/
//struct to get the earlier date
/*
#include<bits/stdc++.h>
using namespace std;
struct date{
    int day;
    int month;
    int year;

};
int main() {
    int n;
    cout << "enter number of dates " << '\n';
    cin >> n;
    date *dates = new date[n];
    for (int i = 0; i < n; i++) {
        cout << "enter the date" << i + 1 << '\n';
        cin >> dates[i].day >> dates[i].month >> dates[i].year;
    }
    date first = dates[0];
    for (int i = 0; i < n; i++) {

        if (dates[i].year < first.year || (dates[i].year == first.year && first.month < first.month) ||
            (dates[i].year == first.year && dates[i].month < first.month && dates[i].day < first.day))
        first = dates[i];
    }

    cout<<"the date is "<<'\n';
    cout<<first.day<<"/"<<first.month<<"/"<<first.year;
    delete[]dates;
 return 0;
}
*/
//struct to find the employee with high salary
/*
#include<bits/stdc++.h>
using namespace std;
struct employee{
    string name;
    float salary;
    string designation;
};
int main(){
    int n;
    cout<<"enter number of employee"<<'\n';
    cin>>n;
    employee*array=new employee[n];
    for(int i=0;i<n;i++){
        cout<<"enter data of employee"<<i+1<<'\n';
        cin>>array[i].name>>array[i].salary>>array[i].designation;
    }
    employee salarys=array[0];
    for(int i=1;i<n;i++){
        if(array[i].salary>salarys.salary){
            salarys=array[i];
        }
    }
    cout<<"the employee with highest salary is "<<'\n'<<salarys.name<<'\n'<<salarys.salary<<'\n'<<salarys.designation;
    delete[]array;
 return 0;
}
*/
//struct books and return the books taht are published after 2000
/*
#include<bits/stdc++.h>
using namespace std;
struct books{
    string title;
    string author;
    int year;
};
int main(){
    int n;
    cout<<"enter the number of books"<<'\n';
    cin>>n;
    books*array=new books[n];
    for(int i=0;i<n;i++){
        cout<<"enter the data of book "<<i+1<<'\n';
        cin>>array[i].title>>array[i].author>>array[i].year;
    }
    for(int i=0;i<n;i++){

        if(array[i].year>2000){
            cout<<"the boks are "<<'\n'<<array[i].title<<'\n'<<array[i].author<<'\n'<<array[i].year<<'\n';
        }
    }
    delete[]array;
 return 0;
}
*/
//struct to calc the average marks of students
/*
#include<bits/stdc++.h>
using namespace std;
struct students{
    string name;
    float mark;
};
int main(){
    int n;
    cout<<"enter the number of students"<<endl;
    cin>>n;
    students*array=new students[n];
    float nums =0;
    for(int i=0;i<n;i++){
        cout<<"data of student"<<i+1<<'\n';
        cin>>array[i].name>>array[i].mark;

    }
    for (int i = 0; i <n ; ++i) {
        nums+=array[i].mark;

    }
    float average=nums/n;
    cout<<"the average marks is "<<'\n'<<average;
 return 0;
}
*/
//function of reversed array
/*
#include<bits/stdc++.h>
using namespace std;
void reverse_array(int arr1[],int size_1){
    int temp;
    for(int i=0;i<size_1/2;i++) {
        temp = arr1[i];
        arr1[i] = arr1[size_1 - 1 - i];
        arr1[size_1 - 1 - i] = temp;
    }
}
int main(){
    int n;
    cout<<"enter the array size"<<'\n';
    cin>>n;
    int arr[n];
    cout<<"enter the array"<<'\n';
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse_array(arr,n);
    cout<<"the reversed are is "<<'\n';
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}
*/
//function that finds the largest element in array
/*
#include<bits/stdc++.h>
using namespace std;
int find_largest_element(int arr1[],int size){
    int max=0;
    for(int i=0;i<size;i++){
        if(arr1[i]>max){
            max=arr1[i];
        }

    }
    return max;
}

int main(){
    int n;
    cout<<"enter the size of array"<<'\n';
    cin>>n;
    int arr[n];
    cout<<"enter array"<<'\n';
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max= find_largest_element(arr,n);
    cout<<"the largest element is"<<'\n'<<max;
 return 0;
}
*/
//struct of students and it returns the averages of marks of each student
/*
#include<bits/stdc++.h>
using namespace std;
struct student{
    string name;
    float *marks;
};
void average(student array[],int size,int mark_num){
    for(int i=0;i<size;i++){
        float average=0;
        for(int j=0;j<mark_num;j++){
        average+=array[i].marks[j];}

    float the_average=average/mark_num;
    array[i].marks[0]=the_average;}



}
int main(){
    int n;
    cout<<"enter the number of students"<<'\n';
    cin>>n;
    int num_of_marks;
    cout<<"enter the number of marks"<<'\n';
    cin>>num_of_marks;
    student students[n];
    cout<<"enter students data "<<'\n';
    for(int i=0;i<n;i++){
        cin>>students[i].name;
        students[i].marks=new float[num_of_marks];
        for(int j=0;j<num_of_marks;j++){
            cin>>students[i].marks[j];
        }
    }
    average(students,n,num_of_marks);
    for(int i=0;i<n;i++){
        cout<<students[i].name<<'\n'<<students[i].marks[0]<<'\n';
    }
    for(int i=0;i<n;i++)
        delete []students[i].marks;
 return 0;
}
*/
//struct with a function to search for book by its title
/*
#include<bits/stdc++.h>
using namespace std;
struct books{
    string title;
    string author;
    int year;
};
books*search_by_books(books*array1 ,int n,string title){
    for(int i=0;i<n;i++){
        if(array1[i].title==title){
            return (&array1[i]);
        }


    }
    return nullptr;
}
int main() {
    int n;
    cout << "enter the number of books" << '\n';
    cin >> n;
    books*array1 = new books[n];
    for (int i = 0; i < n; i++) {
        cin >> array1[i].title >> array1[i].author >> array1[i].year;
    }
    string search;
    cout<<"enter the book name"<<'\n';
    cin>>search;
    books*found_book= search_by_books(array1,n,search);
    if(found_book!= nullptr){
        cout<<found_book->title<<'\n'<<found_book->author<<'\n'<<found_book->year<<'\n';
    }
    else{
        cout<<"not found";
    }
 return 0;
}
*/
//max of two numbers
/*
#include<bits/stdc++.h>
using namespace std;
void max_sum(int a,int b,int&c){
    if(a>b){
        c=a;
    }
    else{
        c=b;
    }
}
int main(){
int a;
int c;
cout<<"enter the first number"<<'\n';
cin>>a;
int b;
cout<<"enter the second number"<<'\n';
cin>>b;
    max_sum(a,b,c);
cout<<"the max number is"<<'\n'<<c;
 return 0;
}
*/
//swap integers &floats in function
/*
#include<bits/stdc++.h>
using namespace std;
void swap_integers(int&a,int&b){
    int temp=a;
    a=b;
    b=temp;
}
void swap_float(float &a,float &b){
    float temp=a;
    a=b;
    b=temp;
}
int main(){
    int num1,num2;
    cout<<"enter num 1 & num2"<<'\n';
    cin>>num1>>num2;
    float n1,n2;
    cout<<"enter n1 &n2"<<'\n';
    cin>>n1>>n2;
    cout<<"integers before swap"<<'\n'<<num1<<'\n'<<num2<<'\n';
    swap_integers(num1,num2);
    cout<<"integers after swap are"<<'\n'<<num1<<'\n'<<num2<<'\n';
    cout<<"float before swap"<<'\n'<<n1<<'\n'<<n2<<'\n';
    swap_float(n1,n2);
    cout<<"float after swap"<<'\n'<<n1<<'\n'<<n2<<'\n';
 return 0;
}
*/
//2d array and get the sum of diagonals
/*
#include <iostream>

// Function to calculate the sum of diagonal elements of a matrix
int sumOfDiagonalElements( int matrix[][4]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += matrix[i][i];  // Adding the diagonal element at position [i][i]
    }
    return sum;
}

int main() {
    int matrix[4][4];

    // Reading elements of the matrix
    std::cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculating the sum of diagonal elements
    int diagonalSum = sumOfDiagonalElements(matrix);

    // Printing the result
    std::cout << "Sum of diagonal elements: " << diagonalSum << std::endl;

    return 0;
}
*/



































