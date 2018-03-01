#include <iostream>
#include <vector>
#include <queue>
#include <cassert>


using namespace std;

class Huffman_table{
    private:
	int word[255];
	int length[255];
        int word2[65525];
        int length2[65525];
    public:
	Huffman_table(){
	}
        pair<int,char> query(uint16_t a){
            char ret = (char) 255 & ((word[a>>8] != -1 ? word[a>>8] : word2[a >> 8]));
            int len = word[a>>8] != -1 ? length[a>>8]: length2[a>>8];
            return pair<int,char>(len,ret);
        }

	Huffman_table(vector<int> a ,vector<char> b){
	    queue<uint16_t> q;
	    q.push(0);
	    q.push(1);
	    int w = 0;
	    for(int i=0;i<8;i++)
	    {
                int remain = 8-i-1;
		for(int j=0;j<a[i];j++)
		{
		    int start = q.front();
                    q.pop();
                    start = start << remain;
                    for(int k=start;k<start +(1 << remain);k++)
                    {
                        word[k] = b[w];
                    }
                    w++;
		}
		int l = q.size();
		for(int j=0;j<l;j++)
		{
		    int a = q.front();
		    q.pop();
		    q.push(2*a);
		    q.push(2*a+1);
		}
	    }
            if(q.empty()) return;
            int start = q.front();
            cout << "aaa " << (start >> 1) <<endl;
            for(int i = (start>>1); i< 256;i++)
            {
                word[i] = -1;
                length[i] = 0;
            }
            for(int i=9;i<16;i++)
            {
                int remain = 16-i-1;
		for(int j=0;j<a[i];j++)
		{
		    int start = q.front();
                    q.pop();
                    start = start << remain;
                    for(int k=start;k<start +(1 << remain);k++)
                    {
                        word2[k] = b[w];
                    }
                    w++;
		}
		int l = q.size();
		for(int j=0;j<l;j++)
		{
		    int a = q.front();
		    q.pop();
		    q.push(2*a);
		    q.push(2*a+1);
		}
            }
	    return;
	}
	void print(){
	    for(int i=0;i<255;i++){
		cout << (char) (word[i] & 255) << " ";
	    }
	    cout << endl;
	}


};

void test1(){
    const char* w = "abcdef";
    int a[16] = {1,1,1,2,0};
    vector<char> words(w,w+6);
    vector<int> sizes(a,a+16);
    Huffman_table h(sizes,words);
    assert(h.query(0).second == 'a');
    assert(h.query(127<<8).second == 'a');
    assert(h.query(129<<8).second == 'b');
    assert(h.query(250<<8).second == 'e');
    return;
}

void test2(){
    const char* w = "abcdefg";
    int a[16] = {0,3,1,2,0};
    vector<char> words(w,w+6);
    vector<int> sizes(a,a+16);
    Huffman_table h(sizes,words);
    assert(h.query(0).second == 'a');
    assert(h.query(127<<8).second == 'b');
    assert(h.query(129<<8).second == 'c');
    assert(h.query(250<<8).second == 'f');
    return;
}

void test3(){
    const char* w = "abcdefg";
    int a[16] = {0,3,1,1,0};
    vector<char> words(w,w+6);
    vector<int> sizes(a,a+16);
    Huffman_table h(sizes,words);
    assert(h.query(0).second == 'a');
    assert(h.query(127<<8).second == 'b');
    assert(h.query(129<<8).second == 'c');
    assert(h.query(230<<8).second == 'e');
    return;
}
int main()
{
    test1();
    test2();
    test3();
    return 0;
}
