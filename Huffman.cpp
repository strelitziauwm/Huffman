#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Huffman{
	private:
		int word[16];
		int length[16];
	public:
		Huffman(){
		}
		Huffman(vector<int> a ,vector<char> b){
			queue<int> q;
			q.push_back(0,1);
			int w=0;
			for(int i=0;i<a.size();i++)
			{
				for(int j=0;j<a[i];j++)
				{
					int start = q.front()
					

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
			for(int i=0;i<16;i++){
				cout << (char) (word[i] & 255) << " ";
			}
			cout << endl;
		}


};

int main()
{
	Huffman h;
	vector<int> sizes(16,0);
	vector<char> words;
	for(int i=0;i<16;i++)
	{
		cin >> sizes[i];
	}
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<sizes[i];j++)
		{
			char c;
			cin >> c;
			words.push_back(c);

		}
	}
	h = Huffman(sizes,words);
	return 0;
}
