int main(){
char pass[20], correct[]="admin123";
for(int i=1;i<=3;i++){
printf("Enter password: ");
scanf("%s", pass);
if(strcmp(pass,correct)==0){
printf("Login Successful"); return 0;
}
printf("Wrong password! Attempts left: %d\n",3-i);
}
printf("Account locked.");
return 0;
}
