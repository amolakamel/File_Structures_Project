import os 
import sys 
 
#sys.path() -> عشان اخلي الحته اللي شغاله فيها جوا اللي بيرن فيها 
#os.getcwd() -> بيجيب انا شغاله فين
#os.chdir() -> بيغير المكان اللي شغاله فيه
# وبعدها اعمل import لاسم الفولدر االي انا شغاله عليه
# ممكن اعمل import + folder name -> كدا هعمل ايه  foldername.functionname()    
# or  from + folder name + import *   -> use function directly
def writeArtist():
    try:
        with open('Artist.txt','a') as file:
             c='y'
             while c=='y':
                 name=input("Enter Artist name: ")
                 Birthplace=input("Enter Artist Birthplace: ")
                 age=input("Enter Artist age: ")
                 Style_Of_Art=input("Enter Style of Art about: ")
                 Year_Of_Art=input("Enter Year it was made: ")
                 file.write(name+'\t'+Birthplace+'\t'+ age +'\t'+Style_Of_Art+'\t'+Year_Of_Art+'\n')
                 c=input('Click y to Add another Artist in The Gallery else Click n : ')
             print("\n<< Artists added Sucessfully ^_^ >>")
             Menu1()
    except IOError:
        print("Can't create the file",'Artist')
 
def readArtist():
    print('Name    BirPlac Age\tStyle of Art\tYear of Art')
    print("------------------------------------------------------")
    with open('Artist.txt','r') as file:
        for line in file:
            print(line)
 
 
def searchArtist():
    name = input('Enter the name of artist you want to search : ')
    with open('Artist.txt','r')as file:
        flag = False 
        for line in file:
            fields = line.split('\t')
            if fields[0] == name:
                flag = True
                print("_________________________________________________________________________")
                print('\nName    BirPlac Age\tStyle of Art\tYear of Art')
                print("------------------------------------------------------")
                print(line)
        if not flag:
            print('The Artist not found :( ')
 
def DeleteArtist():
    import os
    name = input('Enter the name of the Artist to delete : ')
    file = open ('Artist.txt' , 'r')
    tempfile = open ('tempArtist.txt' , 'w')
    flag = False
    for line in file :
 
        aName = line.split('\t')
        if aName[0] == name :
            flag = True
 
        else:
            tempfile.write(line)
 
    file.close()
    tempfile.close()
    os.remove('Artist.txt')
    os.rename('tempArtist.txt','Artist.txt')
    if not flag :
        print ('Artist not found')
    else:
        print ('<< Artist deleted successfully >>')        
 
def UpdateArtist():
    import os
    name     =  input("Enter the Artist Name you want to update: ")
    file     =  open('Artist.txt','r')
    tempfile =  open('tempArtist.txt','w')
    flag     =  False
    for line in file:
        AR = line.split('\t')
        if AR[0] == name:
            flag = True
            option = input("Press 1 to update the Name\nPress 2 to update the Birthplace \nPress 3 to update the Age \nPress 4 to update Style Of Art \nPress 5 to update Year of Art \n")
            if option == '1':
                name = input("Enter the new Artist name : ")
                line = name +'\t'+ AR[1] +'\t'+ AR[2] +'\t'+ AR[3] + '\t' + AR[4]
            elif option == '2':
                Birthplace = input("Enter the new Birthplace : ")
                line = AR[0] +'\t'+ Birthplace +'\t'+ AR[2] +'\t'+ AR[3] + '\t' + AR[4]
            elif option == '3':
                age = input("Enter the new age : ")
                line = AR[0] +'\t'+ AR[1] +'\t'+ age +'\t'+ AR[3] + '\t' + AR[4]
            elif option == '4':
                 Style_Of_Art = input("Enter the new Style Of Art : ")
                 line = AR[0] +'\t'+ AR[1] +'\t'+ AR[2] +'\t'+ Style_Of_Art + '\t' + AR[4]
            elif option == '5':
                 Year_Of_Art = input("Enter the new Year Of Art : ")
                 line = AR[0] +'\t'+ AR[1] +'\t'+ AR[2] +'\t'+ AR[3] + '\t' + Year_Of_Art+'\n'
        tempfile.write(line)
    file.close()
    tempfile.close()
    os.remove('Artist.txt')
    os.rename('tempArtist.txt','Artist.txt')
    if flag:
        print("<< Record successfully updated >>")
    else:
        print("NO Artist are matched :( ")
 
 
 
def Menu1() : 
    c = 'y'
    while c == 'y' :
        print("\n1 : To add new Artist ..\n")
        print("2 : To display all Artists ..\n")
        print("3 : To search for Artist ..\n")
        print("4 : To delete Artist ..\n")
        print("5 : To update Artist's info ..\n")
        n = input("Your choice is .. ? ") 
        if n == '1' :
            writeArtist()
        elif n == '2' :    
            readArtist() 
        elif n == '3' :
            searchArtist()     
        elif n == '4' :
            DeleteArtist()   
        elif n == '5' :
            UpdateArtist()
        else : 
            print("Not found .. \n")         
        c = input("If you want to perform another operation Click y else n  .. ")   
    if c == 'n':
        Main()
       
def Menu2() : 
    c = 'y'
    while c == 'y' :
        print("1 : To display all Artists on the Gallary ..\n")
        print("2 : To search for Artist ..\n")
        n = input("Your choice is .. ? ") 
        if n == '1' :
            readArtist()
        elif n == '2' :    
            searchArtist()     
        else : 
            print("Not found .. \n")         
        c = input("If you want to perform another operation click y else n  .. ")    
    if c =='n':
        Main()
     
def AddUser() :
    with open("user.txt" , 'a') as file :
       c = 'y'
       while c == 'y' :
           name = input("Enter your name ..\n") 
           password = input("Enter your password ..\n") 
           file.write(name + '\t' + password + '\n')
           c = input("If you want to Sign up more Click y else n..\n")
    if c == 'n' :
        print("<< You sign up Successfully >>\n")
        Main()
        
def login() :
 
    name = input("Enter your name : ") 
    password = input("Enter your password : ") 
    fl = False
    with open("user.txt" , 'r') as file :
        for line in file : 
            st = line.split('\t')
            if  st[0] == name and  st[1].strip('\n') == password :
 
                fl = True
                break
        if not fl :
            print("\nNot found .. \n")
            Main()
            return False
        else :                  
            print("\n<< Successfully login Hello " + name +" >>")
            return True
 
def Main() : 
    n = input("Click  1 : For Sign up\nClick  2 : For Login or Guest mood\nClick  3 : For Exit\n")
    if n == '1' :
        AddUser()
    elif n == '2' :
        c = input("Click 1 : If you want to Login  \nClick 2 : If you want the Guest mood \n")    
        if c == '1' : 
           if login() == True :
               Menu1()
           else :
              Main() 
        elif c == '2' :
            Menu2() 
        else :
            print("Invalid choice")
    elif n == '3' :
        print("Thank You for visiting our Gallary ^-^")
        sys.exit();
      
    else : 
        print("Invalid choice")

s="""
██╗░░██╗███████╗██╗░░░░░██╗░░░░░░█████╗░  ████████╗██╗░░██╗███████╗██████╗░███████╗ 
██║░░██║██╔════╝██║░░░░░██║░░░░░██╔══██╗  ╚══██╔══╝██║░░██║██╔════╝██╔══██╗██╔════╝
███████║█████╗░░██║░░░░░██║░░░░░██║░░██║  ░░░██║░░░███████║█████╗░░██████╔╝█████╗░░
██╔══██║██╔══╝░░██║░░░░░██║░░░░░██║░░██║  ░░░██║░░░██╔══██║██╔══╝░░██╔══██╗██╔══╝░░
██║░░██║███████╗███████╗███████╗╚█████╔╝  ░░░██║░░░██║░░██║███████╗██║░░██║███████╗
╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝░╚════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚══════╝""" 
print('\n')
print(s)
print('\n')
print("Welcom To Our Gallary ^-^")
print("------------------------")


Main()
 

