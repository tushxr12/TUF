class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			//your code goes here
			if((a == 2 && (b == 1 || b == 3)) || (b == 2 && (a == 1 || a == 3)))
				return true;
			return false;
		}
};