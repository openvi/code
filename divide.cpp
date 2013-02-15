c class Solution {
    public int divide(int dividend, int divisor) {
       long  divid = dividend;
    long  divis = divisor; 
   if (divis ==0) {
    	return 0;
	}
	if (divid ==0) {
		return 0;
	}
	int flag=1;
	int i=0;
	if (divid<0) {
		flag=-flag;
		divid=-divid;
	}
	if (divis<0) {
		flag=-flag;
		divis=-divis;
	}
    if (divid < divis) {
		return 0;
	} 
	if (divid == divis) {
		return 1*flag;
	} 

	long origin = divis;
	while (divid>=origin) {
	divis=origin;
	int p=0;
	while ((divid > (divis<<1))&&((divis<<1)>0)){
		p++;
		divis=divis<<1;
	}
	divid-=divis;
	i+=1<<p;
	}
	  
	return i*flag;  
    }
};
