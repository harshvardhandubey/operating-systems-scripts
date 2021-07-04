#include&lt;stdio.h&gt;
int main()
{
int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
float awt,atat;
printf(&quot;\nCPU Scheduling Algorithm : Priority \n&quot;);
printf(&quot;\nEnter Total Number of Process : &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\nEnter Process Burst Time : \n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;P[%d] : &quot;,i+1);
scanf(&quot;%d&quot;,&amp;bt[i]);
}
printf(&quot;\nEnter Process Priority : \n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;P[%d] : &quot;,i+1);
scanf(&quot;%d&quot;,&amp;pr[i]);
p[i]=i+1;
}
for(i=0;i&lt;n;i++)
{
pos=i;
for(j=i+1;j&lt;n;j++)
{
if(pr[j]&lt;pr[pos])
pos=j;
}
temp=pr[i];
pr[i]=pr[pos];
pr[pos]=temp;
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0;
for(i=1;i&lt;n;i++)
{
wt[i]=0;
for(j=0;j&lt;i;j++)
wt[i]+=bt[j];
total+=wt[i];
}
awt=total/n;

total=0;
printf(&quot;\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time&quot;);
for(i=0;i&lt;n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf(&quot;\nP[%d]\t\t%d\t\t%d\t\t%d&quot;,p[i],bt[i],wt[i],tat[i]);
}
atat=total/n;
printf(&quot;\n\nAverage Waiting Time : %.2f\n&quot;,awt);
printf(&quot;\nAverage Turnaround Time : %.2f\n&quot;,atat);
return 0;
}