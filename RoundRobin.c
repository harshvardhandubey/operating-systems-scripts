#include&lt;stdio.h&gt;
int main()
{
int i, n, total=0, x, counter=0, tq, wt=0, tat=0, at[10], bt[10], temp[10];
float awt, atat;
printf(&quot;\nCPU Scheduling Algorithm : Round Robin \n&quot;);
printf(&quot;\nEnter Number of Processes : &quot;);
scanf(&quot;%d&quot;,&amp;n);
x = n;
printf(&quot;\nEnter Arrival Time : \n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;P[%d] : &quot;,i+1);
scanf(&quot;%d&quot;, &amp;at[i]);
}
printf(&quot;\nEnter Burst Time : \n&quot;);
for (i=0;i&lt;n;i++)
{
printf(&quot;P[%d] : &quot;,i+1);
scanf(&quot;%d&quot;, &amp;bt[i]);
temp[i] = bt[i];
}
printf(&quot;\nEnter Time Quanta : &quot;);
scanf(&quot;%d&quot;, &amp;tq);
printf(&quot;\nProcess\t\tBurst Time\t Turnaround Time\t Waiting Time\n&quot;);
for(total=0,i=0;x!=0;)
{
if(temp[i]&lt;=tq &amp;&amp; temp[i] &gt; 0)
{
total = total + temp[i];
temp[i] = 0;
counter = 1;
}
else if(temp[i] &gt; 0)
{
temp[i] = temp[i] - tq;
total = total + tq;
}
if(temp[i] == 0 &amp;&amp; counter == 1)
{
x--;
printf(&quot;\nP[%d]\t\t%d\t\t %d\t\t\t %d&quot;, i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
wt = wt + total - at[i] - bt[i];
tat = tat + total - at[i];
counter = 0;
}
if(i == n - 1)
{
i = 0;
}

else if(at[i + 1] &lt;= total)
{
i++;
}
else
{
i = 0;
}
}
awt = wt * 1.0 / n;
atat = tat * 1.0 / n;
printf(&quot;\n\nAverage Waiting Time : %0.2f&quot;, awt);
printf(&quot;\nAverage Turnaround Time : %0.2f\n&quot;, atat);
return 0;
}