#include<vector>
class priorityQueue{
	vector<int> pq;
public:

	priorityQueue(){
	}

	void insert(int data){
		pq.push_back(data);
		int index = pq.size()-1;
		int parent = (index-1)/2;
		while(index>0 && pq[index]<pq[parent]){
			swap(pq[index], pq[parent]);
			index = parent;
			parent = (index-1)/2;
	    }
	}

	void remove(){
		if(pq.size()==0){
			return;
		}
		int index = pq.size()-1;
		pq[0] = pq[index];
		pq.pop_back();
		index--;
		int parent = 0;
		int Lchild = 1, Rchild = 2;
		while(Lchild<=index || Rchild<=index){
			int nextParent = -1;
			if(Lchild<=index && pq[parent]>pq[Lchild]){
				swap(pq[parent], pq[Lchild]);
				nextParent = Lchild;
			}
			if(Rchild<=index && pq[parent]>pq[Rchild]){
				if(nextParent==-1){
					nextParent = Rchild;
				}
				swap(pq[parent], pq[Rchild]);
			}
			if(nextParent==-1){
				break;
			}
			parent = nextParent;
			Lchild = 2*nextParent+1;
			Rchild = 2*nextParent+2;
		}
	}

	bool isEmpty(){
		return pq.size()==0;
	}

    int getSize(){
    	return pq.size();
    }

    int getMin(){
    	if(pq.size()==0){
    		return 0;
    	}
    	return pq[0];
    }
};
