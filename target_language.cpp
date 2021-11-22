#include<iostream>

#include<bits/stdc++.h>
#include <algorithm> 
#include <fstream>
using namespace std;

#include <string>

#include<iterator>

// SHOW TABLES

void min_max(string input,string col,string s);

void display(string input);

void create(string input, vector<string> &cols, vector<string> &d_type,vector<string> &constraint);

void insert(string input, string nums1[10][10]);

int main() {
    
    ifstream inp("input.txt");
    
    int code = 0;
    
    string line;
    
    while (inp) { 
    
        getline(inp,line);
        
        if (code == 0){
            
            if(line == "1"){
                
                // Select Columns
                getline(inp,line);
                
                continue;
                
            }
            
            else if(line == "2"){
                
                // Select MIN , MAX 
                
                getline(inp,line); 
                
                string input = line;
                
                getline(inp,line);

                string s = line; 

                getline(inp,line);
                
                string col = line;
                
                min_max(input,col,s);
                
            }
            
            else if(line == "3"){
                
                string temp = "";
                
                int c = 0;
                
                // Insert Columns 

                getline(inp,line); 
                
                string nums1[10][10];
                
                string input = line; 
                
                getline(inp,line); 

                getline(inp,line); 
                
                for(int i=0;i < line.length();i++){
            
                    if(isblank(line[i])){
                    
                        if(temp != ""){    
                        
                            nums1[0][c] = temp;
                                
                            c++;
                            
                            
                            temp = "";
                        
                          }
                        }
                    
                    else{
                        
                        temp += line[i];
                    
                    }
                    
                    
                }
                
                insert(input,nums1);
                
                continue;
            }
            
            else if(line == "4"){
                
                string temp;
                
                int c = 0;
                
                vector<string> cols;

                vector<string> d_type;
                
                vector<string> constraint;

                getline(inp,line);
                
                string input = line; 
                
                
                
                getline(inp,line);
                
                for(int i=0;i < line.length();i++){
            
                    if(isblank(line[i])){
                    
                        if(temp != ""){    
                        
                            cols.push_back(temp);
                                
                            c++;
                            
                            
                            temp = "";
                        
                          }
                        }
                    
                    else{
                        
                        temp += line[i];
                    
                    }
                    
                    
                }
                
                getline(inp,line);
                
                for(int i=0;i < line.length();i++){
            
                    if(isblank(line[i])){
                    
                        if(temp != ""){    
                        
                            d_type.push_back(temp);
                                
                            c++;
                            
                            
                            temp = "";
                        
                          }
                        }
                    
                    else{
                        
                        temp += line[i];
                    
                    }
                    
                    
                }
                
                getline(inp,line);
                
                for(int i=0;i < line.length();i++){
            
                    if(isblank(line[i])){
                    
                        if(temp != ""){    
                        
                            constraint.push_back(temp);
                                
                            c++;
                            
                            
                            temp = "";
                        
                          }
                        }
                    
                    else{
                        
                        temp += line[i];
                    
                    }
                    
                    
                }
                
                create(input,cols,d_type,constraint);  
                // Create a new file 
                continue;
            }
            
            else if(line == "5"){
                getline(inp,line); 
                
                string input = line;
                
                display(input);
                
            }
            
        }
        
        code++;
        
    }
    
    inp.close();
}    


void min_max(string input,string col,string s){
    
    ofstream outs("output.txt"); 
    
    outs << "2" << "\n"; 


    string line;

    
    
    int idx;
    
    ifstream file(input);
    
    string nums[10][10];    
    
    vector<string> cols;

    vector<string> d_type;

    vector<string> constraint;
    
    int count = 0;
    
    

    while (file) { 
    
        
        getline(file,line);
        
        string temp;
        
        int c = 0;
        
        for(int i=0;i < line.length();i++){
            
            if(isblank(line[i])){
            
                if(temp != ""){    
                
                if (count == 0){
                    
                    cols.push_back(temp);
                    
                }
                
                else if(count == 1){
                    
                    d_type.push_back(temp);
                }

                else if(count == 2){

                    constraint.push_back(temp);
                }
                
                else{
                    
                    nums[count-3][c] = temp;
                    
                    c++;
                }
                
                temp = "";
            
              }
            }
            
            else{
                
                temp += line[i];
            
            }
            
            
        }
        
        count++;
        //cout << line << '\n';
    }
    
    file.close();
    
    

    if(s == "min"){
        
        for(int i = 0;i < cols.size();i++){
            
            
            
            if(cols[i] == col){
                
                
                idx = i;    
                
            }
            
        }
        
        
        
        
        if(d_type[idx] == "float"){
            
            float minimum = 10000.0;
            
            for(int i = 0;i < count - 4;i++){
                
                float temper = stof(nums[i][idx]);
                
                if (minimum > temper){
                    
                    minimum = temper;
                }
                
            }
            
            cout << "minimum: " <<minimum;

            outs<< "Minumum value of this column: " << minimum << "\n";
            
        }
        
        if(d_type[idx] == "double"){
            
            double minimum = 10000.00;
            
            
            
            for(int i = 0;i < count - 4;i++){
                
                float temper = stof(nums[i][idx]);
                
                if (minimum > temper){
                    
                    minimum = temper;
                }
                
            }
            
            cout << "minimum: " <<minimum;

            outs<< "Minumum value of this column: " << minimum << "\n";
        }
        
        
        if(d_type[idx] == "int"){
            
            int minimum = 100;
            
            for(int i = 0;i < count - 4;i++){
                
                
                
                int temper = stoi(nums[i][idx]);
                if (minimum > temper){
                    
                    minimum = temper;
                }
                
            }
            
            cout << "minimum: " <<minimum;

            outs<< "Minumum value of this column: " << minimum << "\n";
            
           
        }
        
        
    
        
    }

    
    
    if(s == "max"){
        
        for(int i = 0;i < cols.size();i++){
            
            
            
            if(cols[i] == col){
                
                
                
                idx = i;    
                break;
                
            }
            
        }
       
            
        if(d_type[idx] == "float"){
            
            float maximum = 0.00;
            
            for(int i = 0;i < count - 4;i++){
                
                float temper = stof(nums[i][idx]);
                
                if (maximum < temper){
                    
                    maximum = temper;
                }
                
            }
            
            cout <<"maximum: " << maximum << endl;

            outs<< "Maximum value of this column: " << maximum << "\n";
            
        }
        
        if(d_type[idx] == "double"){
            
            double maximum = 0.00;
            
            for(int i = 0;i < count - 4;i++){
                
                float temper = stof(nums[i][idx]);
                
                if (maximum < temper){
                    
                    maximum = temper;
                }
                
            }
            
            cout <<"maximum: " << maximum << endl;

            outs<< "Maximum value of this column: " << maximum << "\n";
            
        }
        
        
        if(d_type[idx] == "int"){
            
            int maximum = 0;
            
            for(int i = 0;i < count - 4;i++){

                
                
                float temper = stof(nums[i][idx]);
                
                if (maximum < temper){
                    
                    maximum = temper;
                }
                
            }
            
            cout <<"maximum: " << maximum << endl;

            outs<< "Maximum value of this column: " << maximum << "\n";
            
        }
        
    }
    
    outs.close();
}

void create(string input,vector<string> &cols, vector<string> &d_type,vector<string> &constraint)
{
    
    int i,j,k;
    
    ofstream outs("output.txt"); 

    outs << "4" << "\n";

    ifstream ifile;
    ifile.open(input);
    
    if(ifile) {
          cout<<"file exists";
            outs << "Table already exists !!"; 

            outs.close();
            

    } 
    
    else {

    ifile.close();
    ofstream file(input); 
    
    //vector<string> cols {"col1","col2","col3","col4"};

    //vector<string> d_type {"int","float","varchar","text"};
    
    /*  
    for(i = 0;i < 2;i++){
          
        vector<stirng> temp;  
        
        for(j = 0;j < 2;j++){
              
              string inp;
              
              cin >> inp;
              
              temp.push_back(inp)
            
              
              
          }
          
          cols.push_back(temp);
    }
    */
    
   for(i = 0;i < cols.size();i++){
          
       
        cout << cols[i] << " ";
        
        
        file << cols[i] << " ";
    }

    file << endl;

    for(i = 0;i < d_type.size();i++){
          
          cout << d_type[i] << " ";
          
          file << d_type[i] << " ";

    }

    file << endl;

    for(i = 0;i < d_type.size();i++){
          
          cout << constraint[i] << " ";
          
          file << constraint[i] << " ";

    }

    file << endl;
    
    file.close(); 
    
    outs << "Table created successfully";

    outs.close();

    }
    
}


void insert(string input, string nums1[10][10]){
    
    string line;
    
    int idx;

    
    
    ifstream file(input);

    cout << input;
    
    string nums[100][100];    
    
    vector<string> cols;

    vector<string> d_type;

    vector<string> constraint;
    
    int count = 0;
    
    
    while (file) { 
    
        
        getline(file,line);
        
        string temp;
        
        int c = 0;
        
        for(int i=0;i < line.length();i++){
            
            if(isblank(line[i])){
            
                if(temp != ""){    
                
                if (count == 0){
                    
                    cols.push_back(temp);
                    
                }
                
                else if(count == 1){
                    
                    d_type.push_back(temp);
                }
                
                else if(count == 2){

                    constraint.push_back(temp);
                }

                else{
                    

                    nums[count-3][c] = temp;
                    
                    c++;
                }
                
                temp = "";
            
              }
            }
            
            else{
                
                temp += line[i];
            
            }
            
            
        }
        
        count++;
        cout << line << '\n';
    }
    
    
    file.close();
    
    
    
    int i,j,k;
    
    //string nums1[1][4] = {{"3","3.10","Hwlo","Hy"}};

    ofstream outs("output.txt");

    outs << "3" << "\n";
    
    ofstream fout(input, ios::app);

    int result = 1;

    for(i = 0;i < 1;i++){

    
            
    for(j = 0;j < cols.size(); j++){    //sizeof(nums1[0]) / sizeof(nums1[0][0])

            


            int flag = 1;

            for(int k = 0;k < nums1[i][j].length();k++){

                
                if(d_type[j] == "char" || d_type[j] == "text"){


                      if (!isalpha(nums1[i][j][k])){
                          
                          flag = 0;
                          
                          break;
                      }
                }
                
                if(d_type[j] == "int"){

                      if(!isdigit(nums1[i][j][k])){

                        flag = 0; 

                        break;

                }

            }

            }
            
            
            
            
            if(d_type[j] == "float"){

              if(stoi(nums1[i][j]) == stof(nums1[i][j])){

                flag = 0;

            }

            }
            
            

            if ((constraint[j] == "notnull") && (nums1[i][j] == "null")){
                    
                    
                    outs << "The column shouldn't have a null value !!" << endl;
                    result = 0; //
                    break;
                    
            }

            else if (flag){
            
            cout << nums1[i][j] <<": ACP" << endl;

            

            fout << nums1[i][j] << " ";

            }

            else{

                outs << "Data type mismatch !!";
                result = 0;
                break;

            }

            //cout << nums[i][j] << " ";

        }

        

        

        if (result == 0){

            break;
        }
        fout << "\n";
    }

    
        
    //cout << "\n";
    
    if (result){

    outs << "Data Inserted Successfully." << endl;
    }
    //cout << 5;
    
    fout.close();

    outs.close(); 
}




void display(string input){
    
    string line;
    
    ifstream file(input);
    
    string nums[10][10];    
    
    vector<string> cols;

    vector<string> d_type;

    vector<string> constraint;
    
    int count = 0;
    

    while (file) { 
    
        
        getline(file,line);
        
        string temp;
        
        int c = 0;
        
        for(int i=0;i < line.length();i++){
            
            if(isblank(line[i])){
            
                if(temp != ""){    
                
                if (count == 0){
                    
                    cols.push_back(temp);
                    
                }
                
                else if(count == 1){
                    
                    d_type.push_back(temp);
                }

                else if(count == 2){

                    constraint.push_back(temp);
                }
                
                else{
                    
                    
                    
                    nums[count-3][c] = temp;
                    
                    
                    
                    c++;
                }
                
                temp = "";
            
            }
            }
            
            else{
            temp += line[i];
            }
            
            
        }
        
        
        count++;
        
        //cout << line << '\n';
    }
    
    file.close();


    ofstream outs("output.txt");

    outs << "5" << "\n";
        
    for(int i = 0;i < cols.size();i++){

        cout << cols[i] << " | ";

        outs << cols[i] << " ";


    }

    cout << "\n";

    outs << "\n";

    for(int i = 0;i < d_type.size();i++){

        cout << d_type[i] << " | ";


        outs << d_type[i] << " ";
    }
    cout << "\n";
    outs << "\n";

    for(int i = 0;i < constraint.size();i++){

        cout << constraint[i] << " ";

        outs << constraint[i] << " ";
    }

    cout << "\n";
    outs << "\n";


    for(int i = 0;i < count - 4;i++){
        
        for(int j = 0;j < cols.size();j++){
        
            cout << nums[i][j] << " | ";


            outs << nums[i][j] << " ";      
        }
    
        cout << "\n";

        outs << "\n";
        
    }

    outs.close();    

}
    
