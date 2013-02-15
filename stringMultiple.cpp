ass Solution {
    	public:
		string multiply(string num1, string num2) {
			int i,j,ca,cb,*s;
			string a = num1;
			string b= num2;
			ca=a.size();  
			cb=b.size();  
			s=(int *)malloc(sizeof(int)*(ca+cb)); 
			char *c=(char *)malloc(sizeof(char)*(ca+cb));  
			for(i=0;i<ca+cb;i++) s[i]=0;
			for(i=0;i<ca;i++)  
			{  
				for(j=0;j<cb;j++)  
				{  
					s[i+j+1]+=(a[i]-'0')*(b[j]-'0');  
				}  
			}  
			for(i=ca+cb-1;i>=0;i--)  
			{  
				if(s[i]>9)  
				{  
					s[i-1]+=s[i]/10;  
					s[i]%=10;  
				}  
			}  
			i=0,j=0;  
			while(s[i]==0) i++;  
			while(i<ca+cb)  
			{  
				c[j]=s[i]-'0';  
				j++;  
				i++;  
			}  
			c[j]='';  
			free(s);  
			return c;
			
		}
	};
