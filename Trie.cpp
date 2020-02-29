/////TRIE\\\\\\

struct trie{
	bool endmark;
	trie* next[27];
	trie(){
		endmark=false;
		for(int i=0; i<26; i++) next[i]=NULL;
	}
}*root;
void insert(string str){
	trie* cur = root;
	int len=str.size();
	for(int i=0; i<len; i++){
		int id=str[i]-'a';
		if(cur->next[id]==NULL){
			cur->next[id]=new trie();
		}
		cur=cur->next[id];
	}
	cur->endmark=true;
}
bool search(string str){
	trie* cur = root;
	int len=str.size();
	for(int i=0; i<len; i++){
		int id=str[i]-'a';
		if(cur->next[id]==NULL) return false;
		cur=cur->next[id];
	}
	return cur->endmark;
}
void del(trie* cur){
	for(int i=0; i<26; i++){
		if(cur->next[i]){
			del(cur->next[i]);
		}
	}
	delete(cur);
}
int main()
{
	root = new trie();
	
	del(root);
    return 0;
}
