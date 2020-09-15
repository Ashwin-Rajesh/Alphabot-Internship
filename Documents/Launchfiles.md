# Launchfiles
  
  How to write launchfiles?

---
### About launchfiles
- xml format
- Can run nodes with renamed names, topics

---
### XML format
- Tags
  - Groups      
  ```<something> something else </something>```
  - Single-line   
  ```<something />```
  - Comment     
  ```<!--something-->```
- Attributes
  - Tags can have attributes. Here, tag 'something'  has attribute 'text' with value 'hello' and 'number' with value 'aa'    
  ```<something text="hello" number="aa"/>```
  - Or, for groups    
  ```<something text="hello" number="aa"> ... </something>```

---
# Launchfile specifications
### ```<launch> ... </launch>```    
  - Needs to surround the whole launch file
### ```<node />``` tag   
  - Launches a node
  - Attributes are : 
  - ```pkg```  - required   
  Package of node
  - ```name``` - required   
  Name to launch node
  - ```type``` - required   
  Type of node (the file that can be invoked by rosrun)
  - ```args```  
  Arguments to pass to node
  - ```ns```     
  Namespace to launch node in
  - ```cwd```    
  Change working directory when launching node
  - ```required```    
  Quit whole launch, if this node fails, if set to true
  - ```launch-prefix```   
  Prefix this when invoking the node, we could use this for debugging, setting this as gdb for example
### ```<include />``` tag
  - Used to import some launchfile into current launchfile
  - Attributes are
  - ```file``` - required   
  The path to the launch file
### ```<env />``` tag
  - For setting environment variables
  - Arrtibutes are
  - ```name``` - required
  - ```value``` - required
