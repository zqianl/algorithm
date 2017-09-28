
//С��׼��ȥħ�������ɹ�ħ������,����ħ��������Ҫʹ��ħ����,����С������һöħ���Ҷ�û��,
//����С������̨ħ����������ͨ��Ͷ��x(x����Ϊ0)��ħ���Ҳ��������ħ���ҡ�
//ħ������1:���Ͷ��x��ħ����,ħ�������Ὣ���Ϊ2x+1��ħ����
//ħ������2:���Ͷ��x��ħ����,ħ�������Ὣ���Ϊ2x+2��ħ����
//С�ײɹ�ħ�������ܹ���Ҫn��ħ����,����С��ֻ��ͨ����̨ħ����������ǡ��n��ħ����,
//С����Ҫ��������һ��Ͷ�뷽��ʹ�����ǡ��ӵ��n��ħ���ҡ�

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



//Ϊ�˵õ�һ������"�෴��",���ǽ������������˳��ߵ�,Ȼ���ټ���ԭ�ȵ����õ�"�෴��"��
//����,Ϊ�˵õ�1325��"�෴��",�������ǽ�����������˳��ߵ�,���ǵõ�5231,֮���ټ���ԭ�ȵ���,
//���ǵõ�5231+1325=6556.����ߵ�֮���������ǰ׺��,ǰ׺�㽫�ᱻ���ԡ�����n = 100, �ߵ�֮����1.

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



//һ����Сд��ĸ��ɵ��ַ������Կ���һЩͬһ��ĸ�������Ƭ��ɵġ�
//����,"aaabbaaac"����������Ƭ��ɵ�:'aaa','bb','c'��ţţ���ڸ���һ���ַ���,
//���������������ַ�����������Ƭ��ƽ�������Ƕ��١�

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

//ţţϲ����ɫ�Ķ���,�����ǲ�ɫ�Ĵ�ש��ţţ�ķ���������L�������δ�ש��
//ÿ��ש����ɫ�����ֿ���:�졢�̡������ơ�����һ���ַ���S, 
//���S�ĵ�i���ַ���'R', 'G', 'B'��'Y',��ô��i���ש����ɫ�ͷֱ��Ǻ졢�̡������߻ơ�
//ţţ��������һЩ��ש����ɫ,ʹ�����������ש����ɫ������ͬ�����ţţ������������Ҫ�����Ĵ�ש������ 
//��������:
//�������һ��,һ���ַ���S,�ַ�������length(1 �� length �� 10),�ַ�����ÿ���ַ�������'R', 'G', 'B'����'Y'��
//
//
//�������:
//���һ������,��ʾţţ������Ҫ�����Ĵ�ש����
//
//��������1:
//RRRRRR
//
//�������1:
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

//ţţ��������й�����������һ���ַ�������s,ţţ��Ҫ�������й����ߴ����ҳ����DNA���С�
//DNA����ָ����������ֻ����'A','T','C','G'��ţţ�����������̫����,�Ͱ����⽻�����������
//����: s = "ABCBOATER"�а������DNAƬ����"AT",������ĳ�����2�� 
//��������:
//�������һ���ַ���s,�ַ�������length(1 �� length �� 50),�ַ�����ֻ������д��ĸ('A'~'Z')��
//
//
//�������:
//���һ������,��ʾ���DNAƬ��
//
//��������1:
//ABCBOATER
//
//�������1:
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

//���һ���ַ�����������ͬ�ַ������Ӷ���,�ͳ�����ַ�����ż��������"xyzxyz"��"aaaaaa"��ż��,����"ababab"��"xyzxy"ȴ���ǡ�
//ţţ���ڸ���һ��ֻ����Сд��ĸ��ż��s,����Դ��ַ���s��ĩβɾ��1�ͻ��߶���ַ�,
//��֤ɾ��֮����ַ�������һ��ż��,ţţ��֪��ɾ��֮��õ��ż�������Ƕ��١� 
//��������:
//�������һ���ַ���s,�ַ�������length(2 �� length �� 200),��֤s��һ��ż������Сд��ĸ����
//
//
//�������:
//���һ������,��ʾɾ��֮���ܵõ����ż�������Ƕ��١���֤���������з����
//
//��������1:
//abaababaab
//
//�������1:
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

//ţţ��һЩ��ĸ��Ƭ,ÿ�ſ�Ƭ�϶���һ��Сд��ĸ,���п�Ƭ���һ���ַ���s��
//ţţһֱ��Ϊ������������ʮ������,����ţţϣ������Щ��Ƭƴ�ճ�һЩ���Ĵ�,����������Ҫ��:
//1��ÿ�ſ�Ƭֻ��ʹ��һ��
//2��Ҫ�󹹳ɵĻ��Ĵ�����������
//ţţ��֪������Щ��ĸ��Ƭ,������ƴ�ճ����ٸ����Ĵ���
//����: s = "abbaa",���1,��Ϊ���ٿ���ƴ�ճ�"ababa"��һ�����Ĵ�
//s = "abc", ���3,��Ϊ����ֻ��ƴ�ճ�"a","b","c"���������Ĵ� 
//��������:
//�������һ��,һ���ַ���s,�ַ���s����length(1 �� length �� 1000).
//s��ÿ���ַ�����Сд��ĸ
//
//
//�������:
//���һ������,�����ٵĻ��Ĵ�������
//
//��������1:
//abc
//
//�������1:
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

//ţţ�볢��һЩ�µ�����ÿ��������ҪһЩ��ͬ�Ĳ��ϣ���������е�������Ҫ׼�������ֲ�ͬ�Ĳ��ϡ�
//��������:
//ÿ��������� 1 ������������ÿ�����������ĵ� i �У���ʾ��ɵ� i ��������Ҫ��Щ���ϣ�
//���������ÿո����������ֻ������дӢ����ĸ�Ϳո������ļ������� 50 �У�ÿһ�в����� 50 ���ַ���
//�������:
//���һ��һ�����ֱ�ʾ�������������Ҫ�����ֲ�ͬ�Ĳ��ϡ�
//ʾ��1
//����
//
//BUTTER FLOUR HONEY FLOUR EGG
//���
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

//n ֻ��ţ����һ�ţ�ÿ����ţӵ�� ai ��ƻ����������Ҫ������֮��ת��ƻ����
//ʹ�����������ţӵ�е�ƻ��������ͬ��ÿһ�Σ���ֻ�ܴ�һֻ��ţ��������ǡ������ƻ������һ����ţ�ϣ�
//��������Ҫ�ƶ����ٴο���ƽ��ƻ�������������������� -1��
//��������:
//ÿ���������һ������������ÿ�����������ĵ�һ�а���һ������ n��1 <= n <= 100������������һ�а��� n ������ ai��1 <= ai <= 100����
//�������:
//���һ�б�ʾ������Ҫ�ƶ����ٴο���ƽ��ƻ���������������������� -1��
//ʾ��1
//����
//
//4
//7 15 9 5
//���
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

//�������ӳ�n�����ӣ�����������֮�ʹ���k�ĸ��ʣ��������������ʾ
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

//��һ��ʮ�������ĸ�λ���ֲ����ţ��ж��Ƿ���Գ���ԭ����ʮ��������
//�������Possible���������Impossible
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
	//�Ǳ���������Ϊ2-9����˽�2-9����8������ȫ���𿪣����Ƿ���ԭ������ͬ
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








