from django.shortcuts import render
from django.http import HttpResponse
 

import joblib




# Create your views here.
def home(request):

    d= {'FCFS': 'FCFS (First Come First Serve)','SRTF':'SRTF,Shortest Remaining Time First (Preemtive)',"RR":"Round Robin (Preemtive)","SRJFRR":"SRJFRR"}


    
    
    c={'d':d}
    '''
    res = {
        "data" : [[1, 2, 3, 4, 5, 6],[1, 2, 3, 4, 5, 6]],
    }

    return render(request,'home.html',res)
    '''

    return render(request,'home.html',c)

def add(request):
    

    sentence = request.POST.get("a")

    

    # **********************************************************************************************************************************************************************************


    import nltk

    def parse_select_col(sent):
        try:
            a = []
            grammar = nltk.CFG.fromstring(
            """

            S -> 'select' C 'from' 'idt' ';'
            C ->  '*' | 'idc'A','C | 'idc'A
            A -> '1'A | '1'

            """
            )
            sentence = sent.split()
            parser = nltk.ChartParser(grammar)
            for tree in parser.parse(sentence):
                a.append(tree)
            return True
        except:
            return False
    #parse_select_col("select idc 1 , idc 1 1 from idt ;")
            

    def parse_select_min(sent):
        try:
            a = []
            grammar = nltk.CFG.fromstring(
            """

            S -> 'select' C '(' 'idc1' ')' 'as' 'idc11' 'from' 'idt' ';'
            C ->  'max' | 'min'

            """
            )
            sentence = sent.split()
            parser = nltk.ChartParser(grammar)
            for tree in parser.parse(sentence):
                a.append(tree)
            return True
        except:
            return False
        
    parse_select_min("select min ( idc1 ) as idc11 from idt ;")


    import nltk
    def parse_create(sent):
        try:
            a = []
            grammar = nltk.CFG.fromstring(
                """

                S -> 'create' 'table' 'idt' '(' B ')' ';'
                A ->  'idc'F
                B -> A C D | A C D',' B 
                C -> 'char' | 'varchar' | 'int' | 'float' | 'double' | 'decimal' | 'bool' | 'date' | 'datetime'
                D -> 'null' | 'notnull'
                F ->  '1'F | '1'

                """
            )
            sentence = sent.split()
            parser = nltk.ChartParser(grammar)
            for tree in parser.parse(sentence):
                a.append(tree)
        # print(a)
            return True
        except:
            return False
    parse_create("create table  idt (  idc 1  int null ,  idc 1 1  char null ) ;")


    def parse_insert_into(sent):                                                   
        try:
            a = []
            grammar = nltk.CFG.fromstring(
                """
                S -> 'insert' 'into'  'idt' '(' C ')' 'values' '(' C ')' ';'
                C ->  'idc'A | 'idc'A','C 
                A -> '1'A | '1'

                """
            )
            sentence = sent.split()
            parser = nltk.ChartParser(grammar)
            for tree in parser.parse(sentence):
                a.append(tree)
            return True
        except:
            return False




    # **********************************************************************************************************************************************************************************

    def create(s,d):

        s = s[s.index("(")+1:s.index(")")]
        
        file = open("input.txt", "w") 
        
        result = s.split(",")
        
        file.write('4')
        
        file.write("\n")
        
        file.write(d['idt'])
        
        file.write("\n")
        
        for res in result:
            
            temp = res[res.index("i") : len(res) - res[::-1].index("1")]  
            
            file.write(d[temp])
            
            file.write(" ")
            
            
            print(d[temp],end=" ")
        
        file.write("\n")
        
        for res in result:
            
            temp = res[len(res) - res[::-1].index("1"):].split() 
            
            
            file.write(str(temp[0])+" ")
            
        # file.write(" ")
        
        file.write("\n")

        for res in result:
            
            temp = res[len(res) - res[::-1].index("1"):].split() 
            
        
            file.write(str(temp[-1])+" ")
            
        file.close()

    def insert(s,d):
        

        
        s1 = s[s.index("(")+1:s.index(")")]
        
        print(s1.strip())
        
        
        s2 = s[len(s) - s[::-1].index("(")+1:len(s) - s[::-1].index(")") - 1]
        
        print(s2.strip())
        
        file = open("input.txt", "w") 
        
        
        
        file.write('3')
        
        file.write("\n")
        
        file.write(d['idt'])
        
        file.write("\n")
        
        result1 = s1.split(",")
        
        for res in result1:
            
            temp = res.strip()
            
            file.write(d[temp])
            
            file.write(" ")
            
            
            #print(d[temp],end=" ")
        
        file.write("\n")
        
        result2 = s2.split(",")
        
        for res in result2:
            
            temp = res.strip()
            
            file.write(d[temp])
            
            file.write(" ")
            
            
        file.close()


    def select(s,d):
        
        
        
        s = s[s.index("idc") : s.index("from")]
        
        print(s)
        
        file = open("input.txt", "w") 
        
        file.write('5')
        
        file.write("\n")
        
        file.write(d['idt'])
        
        file.write("\n")
        
        result = s.split(",")
        
        for res in result:
            
            temp = res.strip()
            
            file.write(d[temp])
            
            file.write(" ")
            
            
        file.close()
        
        
    def min_max(s,d):
        
        column = s[s.index("(")+1 : s.index(")")]
        
        variable = s[s.index("as")+2 : s.index("from")]
        
        
        file = open("input.txt", "w") 
        
        file.write('2')
        
        file.write("\n")
        
        file.write(d['idt'])

        file.write("\n") 

        if "min" in s:

            file.write("min")

        elif "max" in s:

            file.write("max")
        
        file.write("\n")
        
        file.write(d[column.strip()])
        
        file.write("\n")
        
        file.write(d[variable.strip()])
            
            
        file.close()
        
        

    # **********************************************************************************************************************************************************************************

        
    #sentence="select roll,name from student ;"
    #sentence="select min ( roll ) as plx from student ;"
    #sentence="create table student ( roll int null  , name char null ) ; "
    #sentence="insert into student ( roll,name ) values ( 8,yuvi ) ;"

    errors = ""

    sl=sentence.split()
    print(sl)
    tl=sl
    di=dict()
    flag_select_min=False
    flag_select_table=False
    flag_create_table=False
    flag_insert_into=False
    if "select" in sl and "from" in sl and "as" not in sl:
        
        l=sl[1].split(',')
        c=len(l)
        dd=dict()
        for i in range(1,c+1):
            s="idc"+" 1"*i
            di[l[i-1]]=s
        
        
        
            
        di[sl[-2]] = "idt"
        print(di)
        flag_select_table=True
    ##"select min ( id 1 ) as id 1 1 from id 1 1 1 ;"    
    elif "select" in sl and "from" in sl and "as" in sl:
        
        di[sl[3]]="idc1"
        di[sl[6]]="idc11"
        di[sl[-2]]="idt"
        flag_select_min=True
    elif "create" in sl and "table" in sl :
        di[tl[2]]="idt"
        c=1
        for i in range(3,len(tl)):
            if i%4==0 and tl[i]!=";":
                di[tl[i]]="idc"+" 1"*c+" "
                c=c+1
        print(di)
        flag_create_table=True
    elif "insert" in sl and "into" in sl:
        for i in range(len(tl)):
            if i==2:
                di[tl[i]]="idt"
            elif i==4:
                c=1
                ss=tl[i].split(',')
                for i in ss:
                    di[i]="idc"+" 1"*c+" "
                    c=c+1
            elif i==8:
                ss=tl[i].split(',')
                for i in ss:
                    di[i]="idc"+" 1"*c+" "
                    c=c+1
        print(di)
        flag_insert_into=True
        

        
        
    #PARSE
    if flag_insert_into:
        s=sentence
        for i in di:
            s=s.replace(i," "+di[i])
        print(s)
        
        if not parse_insert_into(s):
            
            errors = "Error in parsing the given statement !"

        else:
        
            for i in di:
                x=di[i].strip()
                di[i]=x
            dk={v: k for k, v in di.items()}
            
            print(dk)
            insert(s,dk)
        
        
    elif flag_create_table:
        """
        ss=""
        for i in range(2):
            ss=ss+tl[i]+" "
    
        ss=ss+di[tl[2]]+" "
        c=1
        for i in range(3,len(tl)):
            if i%4==0 and tl[i]!=";":
                ss=ss+di[tl[i]]
            else:
                ss=ss+tl[i]+" "
        x=(parse_create(ss))
        print(x)
        """
        s=sentence
        for i in di:
            s=s.replace(i," "+di[i])
        print(s)

        if not parse_create(s):

            errors = "Error in parsing the given statement !"

        else:

            for i in di:
                x=di[i].strip()
                di[i]=x
            dk={v: k for k, v in di.items()}
            
        
            create(s,dk)
        
        

    elif flag_select_min:
        
        tl[3]=di[tl[3]]
        tl[6]=di[tl[6]]
        tl[-2]=di[tl[-2]]
        se=' '.join(tl)
        print(se)

        if not parse_select_min(se):

            errors = "Error in parsing the given statement !"

        else:

            dk={v: k for k, v in di.items()}
            print(dk)
            min_max(se,dk)
        

    elif flag_select_table:
        
        
        
        l=sl[1].split(',')
        
        t = di[sl[-2]]
        
        print("----",sl,di)
        
        ou=""
        
        # "select idc 1 , idc 1 1 , idc 1 1 1 , from idt ;"
        
        for i in range(len(l)):
            
            l[i] = di[l[i]]
            
        print("}{}{}{}{}",sl[0],l,sl[2:-2],t,sl[-1:])
        
        result = sl[0]+ " " + ",".join(l) +" "+"".join(sl[2:-2]) +" "+t +" "+''.join(sl[-1:])
        
        ou = result
        
        print("output:-->",ou)

        if not parse_select_col(ou):

            errors = "Error in parsing the given statement !"

        else:

            dk={v: k for k, v in di.items()}
            print(dk)
            select(ou,dk)
        

        
    #"select min ( id 1 ) as id 1 1 from id 1 1 1 ;"

    if not errors:
    
        import subprocess
        cmd = "app/temp.cpp"
        subprocess.call(["g++", cmd])
        subprocess.call("a.exe")



    out1 = open('output.txt', 'r') 

    Lines = out1.readlines()
    
    

    count = 0
    # Strips the newline character
    
    out_string = ""
    
    lis = []

    if not errors:

        
        for line in Lines[1:]:

            if Lines[0][0] != "5":
            
                out_string += line
            else:
                
                lis.append(line.split()) 

        print("Final:",out_string)    

        print("List:",lis)

        if Lines[0][0] != "5":
            
            if out_string in ["Table already exists !!","Data type mismatch !!"]:
                
                context = {"out_string" : out_string, "dat" : False}
            else:    
                context = {"out_string" : out_string, "dat" : True}

            return render(request,'home.html',context)

        else:
            
            

            context = {"data":lis[3:],"columns" : lis[0],"table":dk['idt']}

            return render(request,'home.html',context)

    else:

        context = {"out_string" : errors, "dat" : False}

        return render(request,'home.html',context)




    ''' 
    data = []
    
    for i in range(n):

        
        

        data.append([process_sno[i],arrival[i],burst_time[i],d_c[i+1],t_a_t[i],waiting_time[i]])


    print(data)

    print(gantt)
    res = {
        "data" : data,
        "Avg_t":Average_turnaround_time,
        "Avg_w":Average_waiting_time,
        "gantt":gantt
    }

    '''


    
    