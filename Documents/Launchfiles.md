# Launchfiles
  
  How to write launchfiles?

---
### About launchfiles
- Capabilities :
  - Can launch other launch files
  - Can run nodes
  - Can make environment variables
  - Can launch parameter servers
- xml format

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
# Substitution tags
  - ```$(env ENVIRONMENT_VARIABLE)```
    - Substituted for variable of ```ENVIRONMENT_VARIABLE```
  - ```$(optenv ENVIRONMENT_VARIABLE DEFAULT_VALUE)```
    - If ```ENVIRONMENT_VARIABLE``` is not defined, value ```DEFAULT_VALUE``` is taken
  - ```$(find PACKAGE_NAME)```
    - Substituted for path to package ```PACKAGE_NAME``` (path from ```rospack find PACKAGE_NAME```
  - ```$(anon NAME)```
    - Substituted for an anonymised version of ```NAME```
    - Multiple invocations on same ```NAME``` give the same result
  - ```$(arg FOO)```
    - Substituted for value specified by argument ```FOO```, defined in an ```<arg>``` tag
  - ```$(dirname)```
    - Substituted for directory name of the launch file
  - ```$(eval EXPRESSION)```
    - Evaluates the ```EXPRESSION```

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
### ```<remap />``` tag   
  - For remapping topics
  - Placed inside ```<node>```, ```<launch>```, or ```<group>``` tags
  - Example
  ```
  <node name=".." ...>
        <remap from=".." to=".." />
  </node>
  ```
  - Arrtibutes are
    - ```from``` - required   
    - ```to``` - required
### ```<arg />``` tag
  - For getting command line arguments
  - Attributes are
    - ```name``` - required
    - ```default```
    Default value of the argument
    - ```value```
    Value of the argument (no need to pass from command line)
    - ```doc```
    For documentaiton
