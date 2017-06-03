#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000009
#define MOD 1000000007
using namespace std;
typedef pair<ll,ll>pii;

/*

bool isPrime[MAX+5];
ll DivisorSum[MAX+5];
ll DivisorNo[MAX+5];
ll modInverse[MAX+5];
ll SmallestPrime[MAX+5];
ll PrimeFactor[MAX+5];
ll Phi[MAX+5];
ll lp[MAX+5];
vector<ll> pr,prime;

void seive_N_logN(ll N)
{
    //calculate prime upto N in NlogN time
    memset(isPrime,true,sizeof isPrime);
    prime.clear();

    isPrime[1]=false;
    for (ll i = 4; i<= N; i=i+2)
        isPrime[i]=false;

    for (ll i = 3; i * i<= N; i=i+2)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    for(ll i=1; i<MAX; i++)
        if(isPrime[i])
            prime.push_back(i);
}

ll SegmentedSieve(ll low, ll high)
{
    //Segmented Seive Gives Number of Primes in a Range
    ll i,j,start,ans;
    ans=0;
    i=0;

    memset(isPrime,true,sizeof isPrime);
    if(low%2==1)//For Odd number
        i++;
    for(i; i<=high-low; i=i+2)
        isPrime[i]=false;

    for(i=3; i<=sqrt(high)+1; i=i+2)
    {
        start=max((ll)ceil(low/i),(ll) 1);
        if(start==1)
            start++;
        start=start*i;

        if(start<low)
            start+=i;

        for(j=start-low; j<=high-low; j=j+i)
        {
            isPrime[j]=false;
        }
    }
    if(low==1)// If low==1 then 1 is not Prime but 2 is Prime
    {
        isPrime[0]=false;
        isPrime[1]=true;
    }
    if(low==2)// If low==2 then 2 is Prime
        isPrime[0]=true;

    for(i=0; i<=high-low; i++)//Checking Prime
    {
        if(isPrime[i])
            ans++;
    }
    return ans;
}

ll SumOfDivisor_logN(ll N)//Sigma Function
{
    //calculate SumOfDivisor for N in logN time
    seive_N_logN(MAX);
    ll ans=1;
    ll cnt,m;
    m=N;
    for (ll i = 2; i*i <= N; i++)
    {
        cnt=0;
        if(m%i==0 && m>0)
        {
            while(m%i==0)
            {
                m=m/i;
                cnt++;
            }
            ans *= (ceil( pow(i,cnt+1) ) - 1)/(i-1); //sigma(p^n) is (p^(n+1)-1)/(p-1)
        }
    }
    if(m>1)
        ans *= (ceil( pow(m,2) ) - 1)/(m-1);

    return ans;
}


void SumOfDivisor_N_logN(ll N)
{
    //calculate SumOfDivisor upto N in NlogN time
    memset(DivisorSum,0,sizeof DivisorSum);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
        {
            DivisorSum[j] += i;
        }
    }
}

void NoOfDivisor_N_logN(ll N)
{
    //calculate NoOfDivisor upto N in NlogN time
    memset(DivisorNo,0,sizeof DivisorNo);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
        {
            DivisorNo[j] += 1;
        }
    }
}

ll NoOfDivisor_logN(ll N)
{
    ll i,m,j,ans;
    ans=1;
    for(i=0; i<prime.size(),prime[i]*prime[i]<=N; i++)
    {
        m=prime[i];
        j=0;
        while(N%m==0)
        {
            j++;
            N=N/m;
        }
        ans=ans*(j+1);
    }
    m=sqrt(N);
    if(m*m!=N)//If n is not a full squqre number then there is a prime number after sqrt(n)
        ans=ans*2;
    return ans;
}

ll phi_for_N(ll N)
{
    ll i,ans;
    ans=N;
    for(i=2; i*i<=N; i++)
    {
        if(N%i==0)
        {
            while(N%i==0)
            {
                N=N/i;
            }
            ans=ans-ans/i;//phi(N)=N(1- 1/p) where p is prime
        }
    }
    if(N>1)
        ans=ans-ans/i;
    return ans;
}

void phi_N_logN(ll N)
{
    //calculate number of coprime upto N in NlogN time
    //first call seive
    for (ll i = 1; i <= N; i++)
        Phi[i] = i;

    for (ll i = 1; i <= N; i++)
    {
        if (isPrime[i])
            for (ll j = i; j <= N; j += i)
                Phi[j] -= Phi[j] / i;
    }
}

void Phi_O_N(ll N)
{
    //calculate coprime upto N in NlogN time
    Phi[1] = 1;
    memset(lp,0,sizeof lp);
    pr.clear();
    for (ll i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            Phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                Phi[i] = Phi[i / lp[i]] * lp[i];
            else
                Phi[i] = Phi[i / lp[i]] * (lp[i] - 1);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

*/

ll modpow (ll a, ll b, ll c)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b=b/2;
    }
    return res;
}

/*

ll Modular_Multiplicative_Inverse (ll a, ll p)
{
    return modpow (a, p - 2, p); // a and p is coprime and p is prime
}

void ModularInverse_O_N(ll N)
{
    //Modular_Multiplicative_Inverse upto N in O(N)
//    a * (m / a) + m % a = m
//   (a * (m / a) + m % a) mod m = m mod m, or
//   (a * (m / a) + m % a) mod m = 0, or
//   (- (m % a)) mod m = (a * (m / a)) mod m.
//    Dividing both sides by (a * (m % a)), we get
//    – inverse(a) mod m = ((m/a) * inverse(m % a)) mod m
//    inverse(a) mod m = (- (m/a) * inverse(m % a)) mod m

    modInverse[1] = 1; // this is you know 1 * 1 mod m = 1
    ll m=MOD;
    for (ll i = 2; i <= N; i++)
    {
        modInverse[i] = (-(m/i) * modInverse[m % i]) % m + m;
    }
}

void SmallestPrimeFactor()
{
    //calculate SmallestPrime upto N in NlogN time
    memset(SmallestPrime,0,sizeof SmallestPrime);
    for (ll i = 2; i < MAX; i += 2)
        SmallestPrime[i] = 2;  //even numbers have smallest prime factor 2
    for (ll i = 3; i < MAX; i += 2)
    {
        if (!SmallestPrime[i])
        {
            SmallestPrime[i] = i;
            for (ll j = i; (j*i) < MAX; j += 2)//j++ produce even number
            {
                if (!SmallestPrime[j*i])
                    SmallestPrime[j*i] = i;
            }
        }
    }
}

void NumberOfPrimeFactor(ll x)
{
    //first call SmallestPrimeFactor
    ll y;
    y=x;
    memset(PrimeFactor,0,sizeof PrimeFactor);
    while(x != 1)
    {
        ll p = SmallestPrime[x];
        while (x % p == 0)
        {
            x /= p;
        }
        PrimeFactor[y]++;
    }
}

ll gcd;

pii ExtendedEuclid(ll a, ll b)   // returns x, y | ax + by = gcd(a,b)
{
    if(a == 0)
    {
        gcd=b;
        return pii(1, 0);
    }
    else
    {
        pii d = ExtendedEuclid(b, a % b);
        return pii(d.second, d.first - d.second * (a / b));
    }
}

ll No_Of_Digits_In_N_Fact_In_Base_B(ll N, ll B)
{

    //The number of digits in N factorial is :
    //floor (ln(n!)/ln(B) + 1)

    ll i;
    double ans=0;
    for(i=1; i<=N; i++)
        ans+= log(i);
    ans=ans/log(B);
    ans=ans+1;

    return (ll)ans;
}

ll No_Of_Trailing_Zeroes_In_N_Fact_In_Base_B(ll N, ll B)
{
    //We can break the Base B as a product of primes :
    // B = a^p1 * b^p2 * c^p3 * ...
    //Then the number of trailing zeroes in N factorial in Base B is given by the formulae
    //min{1/p1(n/a + n/(a*a) + ….), 1/p2(n/b + n/(b*b) + ..), ….}.

    ll i,j,num,ans,total;
    ans=pow(10,10);
    for(i=2; i*i<=B; i++)
    {
        if(B%i==0)
        {
            num=0;
            while(B%i==0)
            {
                B=B/i;
                num++;
            }
            j=1;
            total=0;
            while( floor(N / ceil( pow(i,j) ))> 0 )
            {
                total += N / ceil( pow(i,j) );//No of total i in N!
                j++;
            }
            total = total/num;

            ans=min(ans,total);
        }
    }

    if(B>1)//for last prime
    {
        j=1;
        total=0;
        while(N / ceil( pow(B,j) )>0 )
        {
            total += N / ceil( pow(B,j) );
            j++;
        }
    }

    ans=min(ans,total);

    return ans;
}

*/


int main()
{
    ll n,b,p,m,ans;
    while(scanf("%lld %lld %lld",&b,&p,&m)!=EOF)
    {
        ans=modpow(b,p,m);
        if(b==0 && p==0)
            ans=0;
        printf("%lld\n",ans);
    }
    return 0;
}




