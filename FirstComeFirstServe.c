#include&lt;stdio.h&gt;
int main()
{
int n,at[50],bt[50],wt[50],tat[50],i,j,g[50];
float atat=0,awt=0;
char z;
printf(&quot;\nCPU Scheduling Algorithm : First Come First Serve\n&quot;);
printf(&quot;\nIs The Arrival Time Zero? (y/n) : &quot;);
scanf(&quot;%c&quot;,&amp;z);
if (z==&#39;y&#39;)
{
printf(&quot;\nEnter Number of Process : &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\nEnter Process Burst Time\n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;P[%d]:&quot;,i+1);
scanf(&quot;%d&quot;,&amp;bt[i]);
}
wt[0]=0;
for(i=1;i&lt;n;i++)
{
wt[i]=0;
for(j=0;j&lt;i;j++)
wt[i]=wt[i]+bt[j];
}
for (i=0;i&lt;n;i++)
at[i]=0;
printf(&quot;\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time&quot;);
for(i=0;i&lt;n;i++)
{
tat[i]=bt[i]+wt[i];
awt+=wt[i];
atat+=tat[i];
printf(&quot;\nP[%d]\t%d\t\t%d\t\t%d\t\t%d&quot;,i+1,at[i],bt[i],wt[i],tat[i]);
}
awt/=i;
atat/=i;
printf(&quot;\n\nAverage Waiting Time:%.2f&quot;,awt);
printf(&quot;\nAverage Turnaround Time:%.2f\n&quot;,atat);
return 0;
}
else if (z==&#39;n&#39;)
{
printf(&quot;\nEnter Number of Process : &quot;);
scanf(&quot;%d&quot;,&amp;n);
for(i=0;i&lt;n;i++)
at[i]=0; bt[i]=0; wt[i]=0; g[i]=0;
printf(&quot;\nEnter Process Burst Time\n&quot;);
for(i=0;i&lt;n;i++)

{
printf(&quot;P[%d] : &quot;,i+1);
scanf(&quot;%d&quot;,&amp;bt[i]);
}
printf(&quot;\nEnter Process Arrival Time\n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;P[%d] : &quot;,i+1);
scanf(&quot;%d&quot;,&amp;at[i]);
}
g[0]=0;
for(i=0;i&lt;n;i++)
g[i+1]=g[i]+bt[i];
for(i=0;i&lt;n;i++)
{
wt[i]=g[i]-at[i];
tat[i]=g[i+1]-at[i];
awt+=wt[i];
atat+=tat[i];
}
awt/=n;
atat/=n;
printf(&quot;\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time&quot;);
for(i=0;i&lt;n;i++)
printf(&quot;\nP[%d]\t%d\t\t%d\t\t%d\t\t%d&quot;,i+1,at[i],bt[i],wt[i],tat[i]);
printf(&quot;\n\nAverage Waiting Time : %.2f&quot;,awt);
printf(&quot;\nAverage Turnaround Time : %.2f\n&quot;,atat);
return 0;
}
else
printf(&quot;\n Error!... Invalid Choice!... Exiting&quot;);
return 0;
}