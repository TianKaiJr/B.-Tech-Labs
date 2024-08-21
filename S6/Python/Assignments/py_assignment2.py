from breezypythongui import EasyFrame

class BillingSystem(EasyFrame):
    def __init__(self):
        EasyFrame.__init__(self, title="BILLING SYSTEM")
        self.setBackground("#00FFFF")
        
        self.addLabel(text="PRODUCT NUMBER", row=0, column=0)
        self.prodNumField = self.addIntegerField(value=0, row=0, column=1)
        
        self.addLabel(text="COST", row=1, column=0)
        self.costField = self.addFloatField(value=0.0, row=1, column=1)
        
        self.addLabel(text="QUANTITY", row=2, column=0)
        self.quantityField = self.addIntegerField(value=0, row=2, column=1)
        
        self.addButton(text="ADD PRODUCT", row=3, column=1, command=self.add_product)
        
        self.addLabel(text="PRODUCT LIST", row=4, column=0, columnspan=2)
        self.productList = self.addTextArea("", row=5, column=0, rowspan=5, columnspan=2, width=50, height=10)
        
        self.addButton(text="SUBMIT", row=10, column=0, columnspan=2, command=self.calculate_bill)
        
        self.products = []
        
    def add_product(self):
        prod_num = self.prodNumField.getNumber()
        cost = self.costField.getNumber()
        quantity = self.quantityField.getNumber()
        
        self.products.append((prod_num, cost, quantity))
        
        self.update_product_list()
        
        self.prodNumField.setNumber(0)
        self.costField.setNumber(0.0)
        self.quantityField.setNumber(0)
        
    def update_product_list(self):
        product_str = ""
        for product in self.products:
            product_str += f"PRODUCT NUMBER= {product[0]:5d} | COST= {product[1]:5f} | QUANTITY= {product[2]:5d}\n"
        self.productList.setText(product_str)
        
    def calculate_bill(self):
        total_cost = sum(cost * quantity for _, cost, quantity in self.products)
        self.messageBox(title="FINAL BILL", message=f"TOTAL BILL = ${total_cost:.2f}")

def main():
    BillingSystem().mainloop()

if __name__ == "__main__":
    main()
