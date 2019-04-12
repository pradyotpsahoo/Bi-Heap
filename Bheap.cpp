//include library
#include <iostream>
using namespace std;
//heap class
class heap{
public:
int arr[100];
int end;
heap(){
end = -1 ;
}
//swap function
void swap(int & a, int & b){
int temp = a;
a = b;
b = temp;
}
//insert function
void insert(int val){
arr[end+1] = val;
end = end + 1;
int i = end;
//loop
while(i >0){
if(arr[(i-1)/2 ] > arr[i]){
swap(arr[(i-1)/2], arr[ i]);
i = (i-1)/2;
}
else return;
}
}
//delete function
void Delete(int d) {
swap(arr[d],arr[end ]);
end = end - 1;
int i = d;
//upper upper
while((i>0)&&(arr[(i-1)/2] > arr[i])){
if(arr[(i-1)/2] > arr[i]){
swap(arr[(i-1)/2], arr[ i]);
i = (i-1)/2;
}
}
int j = d;
//below loop
while(((2*j +1)<= end)){
if(2*j+2 <= d){
if(arr[2*j +1] < arr[2*j+2]){
swap(arr[2*j +1], arr[j]);
j = 2*j +1;
}
else {
swap( arr[2*j +2], arr[j]);
j = 2*j +2;
}
}
else{
swap (arr[2*j +1], arr[j]);
j = 2*j +1;
}
}
}
//display function
void display(){
for(int i = 0; i<= end; i++){
cout<<arr[i]<<","; 
}
cout<<endl; 
}
//getminimum function
int getmin(){
return arr[0];
}
//extractmin function
int extractmin(){
int a = arr[0];
Delete(0);
return a;
}
//decresekey function
void decreasekey(int i, int newval){
arr[i] = newval;
while(i>0){
if(arr[(i-1)/2 ] > arr[i]){
swap(arr[(i-1)/2], arr[ i]);
i = (i-1)/2;
}
else return;
}
}
};

int main(void) {
heap h1;
h1.insert (1);
h1.display();
h1.insert(2);
h1.display();
h1.insert(9);
h1.display();
h1.insert(8);
h1.display();
h1.Delete(9);
h1.display();
h1.insert(3);
h1.display();
h1.Delete(1) ;
h1.display();
h1.decreasekey(0,32);
h1.display();
return 0;
}
