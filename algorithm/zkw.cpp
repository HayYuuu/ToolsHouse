#zkw tree by C

#build
int n,M;int d[n<<1];
inline void Build(int n){
    for(M=1;M<n;M<<=1);
    for(int i=M+1;i<=M+n;i++) d[i]=NULL;
}

enum ope {
	SUM,
	MAX,
	MIN
};

inline void Build_init(ope flag){
	switch(flag){
	# Interval sum
	case SUM:
		for(int i=M>>1;i;--i) d[i]=d[i>>1]+d[i>>1|1]; break;
	# Interval max
	case MAX:
		for(int i=M>>1;i;--i) d[i]=max(d[i>>1],d[i>>1|1]); break;
	# Interval min
	case MIN:
		for(int i=M>>1;i;--i) d[i]=min(d[i>>1],d[i>>1|1]); break;
	}
}

# single point change
void Change(int x,int v){
    d[M>>1+x]+=v;
	while(x) d[x>>=1] = update_funtor(d[x<<1],d[x<<1|1]);
}

inline void update_funtor(int left, int right, ope flag ){
	#create a binary operator below 
	
	switch(flag){
	# Interval sum
	case SUM:
		return left+right;
	# Interval max
	case MAX:
		return max(left, right);
	# Interval min
	case MIN:
		return min(left, right);
	}

}

void Build_with_diff(int n){
    for(M=1;M<=n+1;M<<=1);for(int i=M+1;i<=M+n;i++) d[i]=in();
    for(int i=M>>1;i;--i) d[i] = update_funtor(d[i<<1],d[i<<1|1]),d[i<<1]-=d[i],d[i<<1|1]-=d[i];
}

