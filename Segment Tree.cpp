/////SEGMENT TREE\\\\\

struct TREE{
	ll prop, sum;
}tree[MAX*4];
int ar[MAX];
void init(ll node, ll b, ll e){
	if(b==e){
		tree[node].prop=0;
		tree[node].sum=0;
		return;
	}
	ll left=node*2;
	ll right=left+1;
	ll mid=(b+e)/2;
	init(left, b, mid);
	init(right, mid+1, e);
	tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(ll node, ll b, ll e, ll i, ll j, ll x){
	if(i>e || j<b) return;
	if(b>=i && e<=j){
		tree[node].sum+=((e-b+1)*x);
		tree[node].prop+=x;
		return;
	}
	ll left=node*2;
	ll right=left+1;
	ll mid=(b+e)/2;
	update(left, b, mid, i, j, x);
	update(right, mid+1, e, i, j, x);
	tree[node].sum=tree[left].sum+tree[right].sum+((e-b+1)*tree[node].prop);
}
ll query(ll node, ll b, ll e, ll i, ll j, ll carry){
	if(i>e || j<b) return 0;
	if(b>=i && e<=j){
		return tree[node].sum+(carry*(e-b+1));
	}
	ll left=node*2;
	ll right=left+1;
	ll mid=(b+e)/2;
	ll l=query(left, b, mid, i, j, carry+tree[node].prop);
	ll r=query(right, mid+1, e, i, j, carry+tree[node].prop);
	return l+r;
}
int main()
{
	clr(tree, 0);
    return 0;
}
