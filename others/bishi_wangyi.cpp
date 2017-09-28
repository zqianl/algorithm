
//小易准备去魔法王国采购魔法神器,购买魔法神器需要使用魔法币,但是小易现在一枚魔法币都没有,
//但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法币产生更多的魔法币。
//魔法机器1:如果投入x个魔法币,魔法机器会将其变为2x+1个魔法币
//魔法机器2:如果投入x个魔法币,魔法机器会将其变为2x+2个魔法币
//小易采购魔法神器总共需要n个魔法币,所以小易只能通过两台魔法机器产生恰好n个魔法币,
//小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。

#include<iostream>
#include<stack>

using namespace std;

int main(int argc,char **agrv)
{
    int number;
    cin>>number;
    if(number<=0)
        {
        cout<<"Invalid parameter!"<<endl;
        return 0;
    }
    int mid=number;
    stack<char>result;
    while(mid!=0)
        {
        if(mid&1==1)
            result.push('1');
        else
            {
            result.push('2');
            mid--;
        }
        mid=mid/2;
    }
    while(!result.empty())
        {
        cout<<result.top();
        result.pop();
    }
    return 0;
}



//为了得到一个数的"相反数",我们将这个数的数字顺序颠倒,然后再加上原先的数得到"相反数"。
//例如,为了得到1325的"相反数",首先我们将该数的数字顺序颠倒,我们得到5231,之后再加上原先的数,
//我们得到5231+1325=6556.如果颠倒之后的数字有前缀零,前缀零将会被忽略。例如n = 100, 颠倒之后是1.

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(int argc, char **agrv)
{
    int number;
    cin >> number;
    if (number <= 0)
    {
        cout << "Invalid parameter!" << endl;
        return 0;
    }
    vector<int>bitNumber;
    int remain = number;
    int currentNumber;
    while (remain != 0)
    {
        currentNumber = remain % 10;
        remain /= 10;
        bitNumber.push_back(currentNumber);
    }
    int bit = bitNumber.size();
    int exp = bit;
    auto numBegin = bitNumber.begin();
    auto numEnd = bitNumber.end() - 1;
    int result = 0;
    for (int i = 0; i<bit; ++i)
    {
        result += (*numBegin + *numEnd)*pow(10, exp - 1);
        if (i != bit - 1)
        {
            numBegin++;
            numEnd--;
        }
        exp--;
    }
    cout << result << endl;
    return 0;
}



//一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。
//例如,"aaabbaaac"是由下面碎片组成的:'aaa','bb','c'。牛牛现在给定一个字符串,
//请你帮助计算这个字符串的所有碎片的平均长度是多少。

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

int main(int argc, char **agrv)
{
    string s;
    cin >> s;
    if (s.empty())
    {
        cout << "Invalid parameter!" << endl;
        return 0;
    }
    vector<int>midResult;
    double result = 0;
    int count = 1;
    char currChar = *s.begin();
    if (s.size()>1)
    {
        for (auto c = s.begin() + 1; c != s.end(); ++c)
        {
            if (*c == currChar)
                count += 1;
            else
            {
                midResult.push_back(count);
                currChar = *c;
                count = 1;
            }
        }
        midResult.push_back(count);
        for (auto i = midResult.begin(); i<midResult.end(); ++i)
            result += *i;
        result /= midResult.size();
    }
    else
        result = 1;
    cout<<setiosflags(ios::fixed);
    cout.precision(2);
    cout << result << endl;
    return 0;
}

//牛牛喜欢彩色的东西,尤其是彩色的瓷砖。牛牛的房间内铺有L块正方形瓷砖。
//每块砖的颜色有四种可能:红、绿、蓝、黄。给定一个字符串S, 
//如果S的第i个字符是'R', 'G', 'B'或'Y',那么第i块瓷砖的颜色就分别是红、绿、蓝或者黄。
//牛牛决定换掉一些瓷砖的颜色,使得相邻两块瓷砖的颜色均不相同。请帮牛牛计算他最少需要换掉的瓷砖数量。 
//输入描述:
//输入包括一行,一个字符串S,字符串长度length(1 ≤ length ≤ 10),字符串中每个字符串都是'R', 'G', 'B'或者'Y'。
//
//
//输出描述:
//输出一个整数,表示牛牛最少需要换掉的瓷砖数量
//
//输入例子1:
//RRRRRR
//
//输出例子1:
//3

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(int argc, char **argv)
{
    string s;
    cin>>s;
    if(s.size()==0)
        return 0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!='R'&&s[i]!='G'&&s[i]!='B'&&s[i]!='Y')
            return 0;
    }
    int result = 0;
    if(s.size()==1)
        result=1;
    else
    {
        string::iterator s0=s.begin()+1;
        string::iterator s1=s.end();
        while(s0!=s1)
        {
            if(*s0==*(s0-1))
            {
                result++;
                if((s1-s0)>=2)
                {
                    s0 += 2;
                }
                else
                    break;
            }
            else
            {
                s0++;
            }
        }
    }
    cout<<result<<endl;
    system("pause");
    return 0;
}

//牛牛从生物科研工作者那里获得一段字符串数据s,牛牛需要帮助科研工作者从中找出最长的DNA序列。
//DNA序列指的是序列中只包括'A','T','C','G'。牛牛觉得这个问题太简单了,就把问题交给你来解决。
//例如: s = "ABCBOATER"中包含最长的DNA片段是"AT",所以最长的长度是2。 
//输入描述:
//输入包括一个字符串s,字符串长度length(1 ≤ length ≤ 50),字符串中只包括大写字母('A'~'Z')。
//
//
//输出描述:
//输出一个整数,表示最长的DNA片段
//
//输入例子1:
//ABCBOATER
//
//输出例子1:
//2

#include<iostream>
#include<string>

using namespace std;

int main(int argc, char **argv)
{
    string s;
    cin >> s;
    if (s.size() == 0)
        return 0;
    for (int i = 0; i<s.size(); ++i)
    {
        if (s[i]>'Z' || s[i]<'A')
            return 0;
    }
    int maxLength = 0;
    int currLength = 0;
    string::iterator s0 = s.begin();
    string::iterator s1 = s.end();
    while (s0 != s1)
    {
        if (*s0 == 'A' || *s0 == 'T' || *s0 == 'G' || *s0 == 'C')
        {
            currLength++;
            s0++;
        }
        else
        {
            if (maxLength < currLength)
                maxLength = currLength;
            currLength = 0;
            s0++;
        }
    }
    if (maxLength < currLength)
        maxLength = currLength;
    cout << maxLength << endl;
    system("pause");
    return 0;
}

//如果一个字符串由两个相同字符串连接而成,就称这个字符串是偶串。例如"xyzxyz"和"aaaaaa"是偶串,但是"ababab"和"xyzxy"却不是。
//牛牛现在给你一个只包含小写字母的偶串s,你可以从字符串s的末尾删除1和或者多个字符,
//保证删除之后的字符串还是一个偶串,牛牛想知道删除之后得到最长偶串长度是多少。 
//输入描述:
//输入包括一个字符串s,字符串长度length(2 ≤ length ≤ 200),保证s是一个偶串且由小写字母构成
//
//
//输出描述:
//输出一个整数,表示删除之后能得到的最长偶串长度是多少。保证测试数据有非零解
//
//输入例子1:
//abaababaab
//
//输出例子1:
//6

#include<iostream>
#include<string>

using namespace std;

int main(int argc, char **argv)
{
    string s;
    cin >> s;
    if (s.size() == 0)
        return 0;
    if(s.size()&1==1)
        return 0;
    for (int i = 0; i<s.size(); ++i)
    {
        if (s[i]>'z' || s[i]<'a')
            return 0;
    }
    int maxLength = 0;
    string::iterator s0 = s.begin();
    string::iterator s1 = s0 + s.size()/2-1;
    string::iterator s2=s1;
    while(s0<s2)
    {
        if(*s0==*s1)
        {
            s0++;
            s1++;
        }   
        else
        {
            s0=s.begin();
            s2--;
            s1=s2;
        }
    }
    maxLength=2*(s1-s0);
    cout << maxLength << endl;
    system("pause");
    return 0;
}

//牛牛有一些字母卡片,每张卡片上都有一个小写字母,所有卡片组成一个字符串s。
//牛牛一直认为回文这种性质十分优雅,于是牛牛希望用这些卡片拼凑出一些回文串,但是有以下要求:
//1、每张卡片只能使用一次
//2、要求构成的回文串的数量最少
//牛牛想知道用这些字母卡片,最少能拼凑出多少个回文串。
//例如: s = "abbaa",输出1,因为最少可以拼凑出"ababa"这一个回文串
//s = "abc", 输出3,因为最少只能拼凑出"a","b","c"这三个回文串 
//输入描述:
//输入包括一行,一个字符串s,字符串s长度length(1 ≤ length ≤ 1000).
//s中每个字符都是小写字母
//
//
//输出描述:
//输出一个整数,即最少的回文串个数。
//
//输入例子1:
//abc
//
//输出例子1:
//3

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char **argv)
{
    string s;
    cin >> s;
    if (s.size() == 0)
        return 0;
    for (int i = 0; i<s.size(); ++i)
    {
        if (s[i]>'z' || s[i]<'a')
            return 0;
    }
    int minLength = 0;
    string::iterator s0 = s.begin();
    string::iterator s1 = s.end();
    vector<int>mapResult(26,0);
    while(s0!=s1)
    {
        mapResult[*s0-97]++;
        s0++;
    }
    for(unsigned int i=0; i<mapResult.size(); ++i)
    {
        if(mapResult[i]&1==1)
            minLength++;
    }
    cout<<minLength<<endl;
    system("pause");
    return 0;
}

//牛牛想尝试一些新的料理，每个料理需要一些不同的材料，问完成所有的料理需要准备多少种不同的材料。
//输入描述:
//每个输入包含 1 个测试用例。每个测试用例的第 i 行，表示完成第 i 件料理需要哪些材料，
//各个材料用空格隔开，输入只包含大写英文字母和空格，输入文件不超过 50 行，每一行不超过 50 个字符。
//输出描述:
//输出一行一个数字表示完成所有料理需要多少种不同的材料。
//示例1
//输入
//
//BUTTER FLOUR HONEY FLOUR EGG
//输出
//
//4


#include<iostream>
#include<set>
#include<string>
#include<sstream>

using namespace std;

int main(int argc, char **argv)
{
    string line;
    set<string> result;
    while(getline(cin,line))
    {
        istringstream s(line);
        string material;
        while(s>>material)
        {
            result.insert(material);
        }
    }
    int numMaterial=result.size();
    cout<<numMaterial<<endl;
    system("pause");
    return 0;
}

//n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，
//使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，
//问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
//输入描述:
//每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
//输出描述:
//输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。
//示例1
//输入
//
//4
//7 15 9 5
//输出
//
//3

#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

int main(int argc, char **argv)
{
    int numCow;
    vector<int>appleData;
    cin>>numCow;
    int numApple;
    for(int i=0;i<numCow;++i)
    {
        cin>>numApple;
        appleData.push_back(numApple);
    }
    int oddOrNot=*appleData.begin()&1;
    int sumApple=*appleData.begin();
    int result=-1;
    bool flag=1;
    for(auto i=appleData.begin()+1;i<appleData.end();++i)
    {
        if((*i&1)==oddOrNot)
        {
            sumApple+=*i;
        }
        else
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        int meanApple=sumApple/appleData.size();
        int remain=sumApple%appleData.size();
        if(remain==0)
        {
            result=0;
            for(auto i=appleData.begin();i<appleData.end();++i)
            {
                int diff=abs((*i)-meanApple);
                if((diff & 1)==0)
                    result+=diff/2;  
                else
                {
                    result=-1;
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                result /= 2;
        }
    }
    cout<<result<<endl;
    system("pause");
    return 0;
}

//求随意扔出n个骰子，向上面数字之和大于k的概率，输出用最简分数表示
#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>

using namespace std;

int g_maxValue = 6;

void PrintProbability(int number, int x)
{
	if (x <= number)
		cout << "1" << endl;
	else if (x>(6 * number))
		cout << "0" << endl;
	else
	{
		vector<vector<long long>>probabilities(2, vector<long long>(g_maxValue*number + 1, 0));
		int flag = 0;
		for (int i = 1; i <= g_maxValue; ++i)
			probabilities[flag][i] = 1;
		for (int k = 2; k <= number; ++k)
		{
			for (int i = 0; i < k; ++i)
				probabilities[1 - flag][i] = 0;
			for (int i = k; i <= g_maxValue*k; ++i)
			{
				probabilities[1 - flag][i] = 0;
				for (int j = 1; j <= i&&j <= g_maxValue; ++j)
					probabilities[1 - flag][i] += probabilities[flag][i - j];
			}
			flag = 1 - flag;
		}
		long long total = pow(g_maxValue, number);
		long long sum = 0;
		for (int i = x; i <= g_maxValue*number; ++i)
			sum += probabilities[flag][i];
		while (((sum & 1) == 0) && ((total & 1) == 0))
		{
			sum /= 2;
			total /= 2;
		}
		while (((sum % 3) == 0) && ((total % 3) == 0))
		{
			sum /= 3;
			total /= 3;
		}
		cout << sum << "/" << total << endl;
	}
}

int main(int argc, char **argv)
{
	int n, x;
	cin >> n >> x;
	PrintProbability(n, x);
	system("pause");
	return 0;
}

//将一个十进制数的各位数字拆开重排，判断是否可以除尽原来的十进制数，
//是则输出Possible，否则输出Impossible
#include<iostream>
#include<vector>
#include<set>

using namespace std;

multiset<int> SingleNum(int data)
{
	multiset<int> midSingleNum;
	while (data != 0)
	{
		int remain = data % 10;
		midSingleNum.insert(remain);
		data /= 10;
	}
	return midSingleNum;
}

void JudgeMultiOrNot(const int &data)
{
	vector<int>vecMulti;
	//是倍数则倍数必为2-9，因此将2-9倍的8个数字全部拆开，看是否与原数字相同
	for (int i = 1; i <= 9; ++i)
	{
		vecMulti.push_back(i*data);
	}
	vector<multiset<int>> vecSingleNum;
	for (auto i = vecMulti.begin(); i != vecMulti.end(); ++i)
	{
		multiset<int> multiData = SingleNum(*i);
		vecSingleNum.push_back(multiData);
	}
	bool flag = false;
	for (auto i = vecSingleNum.begin() + 1; i != vecSingleNum.end(); ++i)
	{
		if (*i == *vecSingleNum.begin())
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
}

int main(int argc, char **argv)
{
	int numData;
	cin >> numData;
	vector<int> vecData;
	int element;
	for (int i = 0; i < numData; ++i)
	{
		cin >> element;
		vecData.push_back(element);
	}
	for (auto i = vecData.begin(); i != vecData.end(); ++i)
	{
		JudgeMultiOrNot(*i);
	}
	system("pause");
	return 0;
}








