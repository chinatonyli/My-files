package main

//import "fmt"
import "strconv"
import "os"

func main(){
        var (
                a=0
                b=0
        )
        m,_:=strconv.Atoi(os.Args[1])
        h:=(m+m%2)/2
        for a=1;a<h;a++{
                if h>2*a {
                        b=h-a
                }else{
                        b=a
                }
                for ;b<h;b++ {
                        if (2*b>=m-a)&&(2*a<=m-b){
                                //fmt.Printf("%d,%d,%d\n",a,b,m-a-b)
                        }
                }
        }
}
