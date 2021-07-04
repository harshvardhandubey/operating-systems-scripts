#include &lt;stdio.h&gt;
int mutex=1,full=0,buffsize=3,x=0;
int main()
{
int n;
void producer();
void consumer();
int wait(int);
int signal(int);
printf(&quot;\n Producer Consumer Problem : Bounded Buffer Problem \n&quot;);
printf(&quot;\n 1.Producer\n 2.Consumer\n 3.Exit \n&quot;);
while(1)
{
printf(&quot;\n Enter your choice : &quot;);
scanf(&quot;%d&quot;,&amp;n);
switch(n)
{
case 1:
if((mutex==1)&amp;&amp;(buffsize!=0))
producer();
else
printf(&quot;\n Error!... Buffer Full!&quot;);
break;
case 2:
if((mutex==1)&amp;&amp;(full!=0))
consumer();
else
printf(&quot;\n Error!... Buffer Empty!&quot;);
break;
case 3:
return 0;
break;
}
}
return 0;
}
int wait(int s)
{
return(--s);
}
int signal(int s)
{
return(++s);
}
void producer()
{
mutex=wait(mutex);

full=signal(full);
buffsize=wait(buffsize);
x++;
printf(&quot;\n Producer Produces Item %d&quot;,x);
mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
full=wait(full);
buffsize=signal(buffsize);
printf(&quot;\n Consumer Consumes Item %d&quot;,x);
x--;
mutex=signal(mutex);
}