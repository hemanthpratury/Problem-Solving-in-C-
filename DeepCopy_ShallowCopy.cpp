#include<iostream>
#include<array>
#include<cstring>

using namespace std;

class Basic_vector {
	public:
		int* givenArray;
		int* ultimateArray;
		int dynamic_ArraySize;
		Basic_vector(int size);
		Basic_vector(){
			
		}
		int* copy(int* previousArray,int* currentArray){
			currentArray=previousArray;
			return currentArray;	
		}
		int* getInputArray() {
			return givenArray;	
		}
};

int* Reversing_array(int* local_array, int size) {
			int dynamic_ArraySize=size;
			for (int i=0; i<dynamic_ArraySize/2; i++) {
        	int temp = local_array[i];
        	local_array[i] = local_array[dynamic_ArraySize-i-1];
        	local_array[dynamic_ArraySize-i-1] = temp;
			}
			return local_array;
}

// Constructor of MyArrayaCopy
Basic_vector::Basic_vector(int size) {
		dynamic_ArraySize=size;
		givenArray = new int[dynamic_ArraySize];
		for(int i=0;i<dynamic_ArraySize;i++){
				givenArray[i]=i;
		}
}

//Inheritance from parent class
class child_vector : public Basic_vector {
	public:
	child_vector(int size): Basic_vector(size) {

	}
	
	child_vector(): Basic_vector(){
		
	}
	int* copy(int* previousArray,int* currentArray) {
		for(int k=0;k<dynamic_ArraySize;k++) {
			currentArray[k]=previousArray[k];	
		}
		return currentArray;
	}
};

ostream &operator<< (std::ostream &out, Basic_vector &myarray) {
		out << myarray.ultimateArray[0];
        for ( int i = 1 ; i < myarray.dynamic_ArraySize ; i++ )
        {
            out << "," << myarray.ultimateArray[i];
        }
	out << '\n';
	return out;
}

int main(int argc, char *argv[]) {
	if(argc==1) {
	cerr<<"Enter arguments as #./filename #-s #size_number then proceed.. "<<endl;
	return -1;
    }
	int size;
	int* previousArray;
	int* currentArray;
	string previous_status;
	string current_status;
	if(strcmp(argv[1],"-s")!=0) {
		cerr<<"Array Size missing. Provide the size of array"<<endl;
		exit(0);
	}
	else {
		if(true){ //check arg2 is int or not
			size = atoi(argv[2]);
			
			
			//argv[3] check.
			if(strcmp(argv[3],"-S")==0||strcmp(argv[3],"-D")==0){
				if(strcmp(argv[3],"-S")==0){
						Basic_vector myarray(size);
						currentArray=myarray.getInputArray();
						current_status="shallowcopy_mode";
				}
				else{
						child_vector myvector(size);
						currentArray=myvector.getInputArray();
						current_status="deepcopy_mode";
				}
			}
			else {
				//cerror	
			}
			
			
			
			//argv[4] check
			if(strcmp(argv[4],"-S")==0||strcmp(argv[4],"-D")==0||strcmp(argv[4],"-R")==0||strcmp(argv[4],"-O")==0){
				if(strcmp(argv[4],"-S")==0){
						previousArray=currentArray;
						Basic_vector myarray(size);
						currentArray=myarray.getInputArray();
						previous_status=current_status;
						current_status="shallowcopy_mode";
				}
				else if(strcmp(argv[4],"-D")==0){
						previousArray=currentArray;
						child_vector myvector(size);
						currentArray=myvector.getInputArray();
						previous_status=current_status;
						current_status="deepcopy_mode";
				}
				else if(strcmp(argv[4],"-R")==0){
						currentArray=Reversing_array(currentArray,size);
				}
				else if(strcmp(argv[4],"-O")==0){
					if(argc-1==4){
						Basic_vector myarray;
						myarray.ultimateArray=currentArray;
						cout<<myarray<<endl;
					}
					/*else if(strcmp(argv[5],"p")==0) {
						Basic_vector myarray;
						myarray.ultimateArray=previousArray;
						cout<<myarray<<endl;
					}*/
					else{
						//cerr	
					}
				}
			}
			else { //argv4 else
				//cerror	
			}
			
			//After argv4 block
			for(int i=5;i<argc;i++){
					if(strcmp(argv[i],"-S")==0||strcmp(argv[i],"-D")==0||strcmp(argv[i],"-R")==0||strcmp(argv[i],"-O")==0||strcmp(argv[i],"-C")==0){
							if(strcmp(argv[i],"-S")==0){
								previousArray=currentArray;
								Basic_vector myarray(size);
								currentArray=myarray.getInputArray();
								previous_status=current_status;
								current_status="shallowcopy_mode";
							}
							else if(strcmp(argv[i],"-D")==0){
								previousArray=currentArray;
								child_vector myvector(size);
								currentArray=myvector.getInputArray();
								previous_status=current_status;
								current_status="deepcopy_mode";
							}
							else if(strcmp(argv[i],"-R")==0){
								currentArray=Reversing_array(currentArray,size);
							}
							else if(strcmp(argv[i],"-O")==0){
								if(i==argc-1){
									Basic_vector myarray;
									myarray.ultimateArray=currentArray;
									cout<<myarray<<endl;	
								}
								else {
									if(strcmp(argv[i+1],"p")==0){
										Basic_vector myarray;
										myarray.ultimateArray=previousArray;
										cout<<myarray<<endl;
									}
								}
							}
							else if(strcmp(argv[i],"-C")==0){
								if(current_status.compare("deepcopy_mode")==0){
									child_vector myvector;
									currentArray=myvector.copy(previousArray,currentArray);
								}
								else {
									Basic_vector myarray;
									currentArray=myarray.copy(previousArray,currentArray);
								}
							}
							else{
								//cerror	
							}
					}
					else{ 
						//cerror after argv4 else block.
					}
			}
			
		}
		else{// size check else
			// cerror	
		}
	}
}	
