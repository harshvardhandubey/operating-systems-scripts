#include&lt;stdio.h&gt;
int main()
{
int temp, i, j, n, sum = 0, position;
float awt, atat;
int bt[20], process[20], wt[20], tat[20];
printf(&quot;\nCPU Scheduling Algorithm : Shortest Job First (Non-Preemptive) \n&quot;);
printf(&quot;\nEnter Number of Processes : &quot;);
scanf(&quot;%d&quot;, &amp;n);
printf(&quot;\nEnter Burst Time For Process : \n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;P[%d] : &quot;,i+1);
scanf(&quot;%d&quot;, &amp;bt[i]);
process[i] = i + 1;
}
for(i=0;i&lt;n;i++)
{
position = i;
for(j=i+1;j&lt;n;j++)
{
if(bt[j]&lt;bt[position])
position = j;
}
temp = bt[i];
bt[i] = bt[position];
bt[position] = temp;
temp = process[i];
process[i] = process[position];
process[position] = temp;
}
wt[0] = 0;
for(i=1;i&lt;n;i++)
{
wt[i] = 0;
for(j = 0; j &lt; i; j++)
wt[i]+=bt[j];
sum+=wt[i];
}
awt = (float)sum / n;
sum = 0;
printf(&quot;\nProcess ID\tBurst Time\t Waiting Time\t Turnaround Time\n&quot;);
for(i=0;i&lt;n;i++)
{
tat[i] = bt[i] + wt[i];
sum+=tat[i];
printf(&quot;P[%d]\t\t%d\t\t %d\t\t %d\n&quot;, process[i], bt[i], wt[i], tat[i]);
}
atat = (float)sum / n;
printf(&quot;\nAverage Waiting Time : %.2f\n&quot;, awt);
printf(&quot;\nAverage Turnaround Time : %.2f\n\n&quot;, atat);
return 0;
}