
double **createMat(int m, int n);
void readMat(double **p, int m,int n);
double** matsum(double **mat1,double **mat2);
void print(double **p,int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double **a,int m);
double **scalarProduct(double scalar,double **mat);

//defining the function for matrix creation 
double **createMat(int m, int n) {  
    int i, j;  
    double **a;  
      
    // Allocate memory to the pointer  
    a = (double **)malloc(m * sizeof(*a));  
      
    for (i = 0; i < m; i++) {  
        a[i] = (double *)malloc(n * sizeof(*a[i]));  
        for (j = 0; j < n; j++) {  
            a[i][j] = 0.0;  
        }  
    }  
      
    return a;  
}  
 
//end function for the matrix creation 
 
//Defining the function for reading matrix  
void readMat(double **p, int m,int n) 
{ 
 int i,j; 
 for(i=0;i<m;i++) 
 { 
  for(j=0;j<n;j++) 
  { 
   scanf("%lf",&p[i][j]); 
  } 
 } 
} 
//End function for reading matrix 
 
//Read  matrix from file 
double **loadtxt(char *str,int m,int n) 
{ 
FILE *fp; 
double **a; 
int i,j; 
} 
//end function for reading of matrix

void print(double **p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", p[i][j]);
        }
        printf("\n");
    }
}

 //  adding of the two matrices a and b
double **matc(double **mat1, double **mat2) {
    double **sum = (double** )malloc(3 * sizeof(*sum));
    for (int i = 0; i < 3; i++) {
        sum[i] = (double*)malloc(sizeof(double));
        sum[i][0] = mat1[i][0] + mat2[i][0];
    }

    return sum;
}
// end the ouput with c

//finding the norm 
double linalg_norm(double **a, int m) {
    double norm = 0.0;

    for (int i = 0; i < m; i++) {
        norm += a[i][0] * a[i][0];
    }

    return sqrt(norm);
}
// finding the scalar product of magnitude 5 units
double **scalarProduct(double scalar, double **mat) {
    double **product = (double**)malloc(3 * sizeof(*product));

    for (int i = 0; i < 3; i++) {
        product[i] = (double*)malloc(sizeof(double));
        product[i][0] = mat[i][0] * scalar;
    }

    return product;
}
//end with the output
void save_vector(double **a, int rows, int cols)
{
 FILE *fp;
 fp = fopen("vector.dat", "w");
 //fprintf(fp, "The result of the multiplication is:\n");
  int i, j; 
  for (i = 0; i < rows; i++) {
   //fprintf(fp, "[");
   for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {  
       //fprintf(fp, ", ");  
       }
    } 
   fprintf(fp, "\n"); 
  }
  fclose(fp);
}





double **load_ser(AsyncWebServerRequest *request,const char* matrix1[3])
{
	double **a;
	int m=3,n=1;
	a = createMat(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=request->getParam(matrix1[i])->value().toDouble();
		}
	}
	return a;
}

double **load_serv(AsyncWebServerRequest *request,const char* matrix2[3])
{
	double **a;
	int m=3,n=1,k=0;
	a = createMat(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=request->getParam(matrix2[k])->value().toDouble();
			k+=1;
		}
	}
	return a;
}

