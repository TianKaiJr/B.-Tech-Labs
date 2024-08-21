#include <stdio.h>

void main()
{
	int n, m, i, j, k;
	printf("Number Of Processes = ");
	scanf("%d",&n);
	printf("Number Of Resources = ");
	scanf("%d",&m);
	
	int alloc[n][m];
	int max[n][m];
	int avail[m];
	
	printf("ALLOCATED MATRIX \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	
	printf("MAX MATRIX \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("AVAILABLE RESOURCES\n");
	scanf("%d %d %d %d",&avail[0],&avail[1],&avail[2],&avail[3]);

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			flag=0;
			printf("SYSTEM NOT SAFE");
			break;
		}
	}
	
	if(flag==1)
	{
	printf("SAFE Sequence >> ");
	for (i = 0; i < n - 1; i++)
		printf("P%d-> ", ans[i]);
	printf("P%d\n", ans[n - 1]);
	}
}



