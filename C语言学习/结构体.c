
struct Student
{
    int id;
    char name[10];
    char major[20];
    /* data */
};

int main(){
    //创建结构体
    //方式一
    struct Student Alice;
    //方式二(这种方式仅适用于C++)
    //Student Jack;

    //访问结构体内的元素 "."and"->"操作
    Alice.id = 10;

    //字符数组仅可以在初始化时对整个字符数组操作
    Alice.major[1] = 'C';
    //访问结构体指针变量内的元素使用"->"操作更方便
    return 0;
}