try:
    a=int(input("enter a number"))
    b=int(input("enter a number"))
    divison=float(a/b)
    print(f"divison:{divison:.2f}")
except ZeroDivisionError:
    print("b is not valid")
except ValueError:
    print("invalid input")
except:
    print("some error occured")

    