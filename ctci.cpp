															//CRACKING THE CODING INTERVIEW PROBLEMS AND SOLVING
//CHAPTER 1: ARRAYS STRINGS
	//1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
		public bool isUnique(string s){
			//So aside from O(n) with memoizing and O(n^2) brute force there's another approach
			//checker can basically have 26 bits for each letter of the alphabet
			int checker = 0;
			for(int i = 0;i<s.size();i++){
				int val = s[i]-'a';
				if(checker&(1<<val)>0) 
					return false; //here checker bit of that index of the character if set will be greater than zero meaning it was set before hence repeat
				checker|=(1<<val);//here setting checker bit
			}

			return true;
		}

	//1.3 Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. only one two variables allowed
		public void removeDuplicate(string s){
			//can use the checker from unique and then delete that occurence
			if(s==null) return;
			if(s.size()<2) return s;
			
		}