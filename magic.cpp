#include <iostream>
#include <vector>
using namespace std;
void matrix(){
    int cols,rows;
    std::cout<<"Please enter the size of matrix : ";
    std::cin>>rows;
    cols = rows;
    int size = cols;
    int i,j;
    int A[rows][cols];
    for(i = 0; i <rows; i++){
        for(j = 0; j<cols; j++){
            std::cout<<"Enter value : ";
            std::cin>>A[i][j];
        }
    }
            std::cout<<"_________________________"<<std::endl;
            std::cout<<"Displaying matrix"<<std::endl;
            std::cout<<"_________________________"<<std::endl;
            std::cout<<"\n";
    for(int i = 0; i <rows; i++){
        for(int j = 0; j<cols; j++){
            std::cout<<"\t"<<A[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
            // std::cout<<"\n";
            // std::cout<<"_________________________"<<std::endl;
            // std::cout<<"Summation of matrix"<<std::endl;
            // std::cout<<"_________________________"<<std::endl;
            // std::cout<<"\n";
     vector<int> sum_rows(size,0);
     vector<int> sum_cols(size,0);
    int first_diagonal = 0;
    int second_diagonal = 0;
        for(i = 0; i <rows; i++){
            for(j = 0; j<cols;j++){
                int array = A[i][j];
                    sum_rows[i] += array;
                    sum_cols[j] += array;
             
             //To check diagonal 
                if(i == j){
                 first_diagonal += A[i][j];
                }
                if(i + j == size - 1){
                 second_diagonal += A[i][j];
                }
            }
        }
    
    //Displaying the summation of Rows,columns, and Diagnols.
    // cout<<"_________________________________________"<<endl;
    // for(i = 0; i<size; i++){
    //     cout<<"summation of rows "<<i+1<<" : "<<sum_rows[i]<<endl;
    // }
    // cout<<"_________________________________________"<<endl;
    // for(j = 0; j<size; j++){
    //     cout<<"summation of cols "<<j+1<<" : "<<sum_cols[j]<<endl;
    // }
    // cout<<"_________________________________________"<<endl;
    
    // cout<<"summation of Both diagonals : "<<first_diagonal<<endl;
    // cout<<"summation of Both diagonals : "<<second_diagonal<<endl;
    // cout<<"_________________________________________"<<endl;
    
    bool square_mat = true;
    int diagonal_one = first_diagonal;
    for(i = 0; i < size; i++){
        if(sum_rows[i] != diagonal_one || sum_cols[i] != diagonal_one){
            square_mat = false;
            break;
        }
    }

    if(square_mat && second_diagonal == diagonal_one){
        cout<<"_____________________________"<<endl;
        cout<<"This is Magic matrix!"<<endl;
        cout<<"Congratulations!"<<endl;
        cout<<"_____________________________"<<endl;
    }
    else{
        cout<<"_____________________________"<<endl;
        cout<<"This is not magic matrix!"<<endl;
        cout<<"Try again!"<<endl;
        cout<<"_____________________________"<<endl;
    }
}


int main() {
matrix();

    return 0;
}
