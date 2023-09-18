This file contains all the model solutions of the _BioptyhonActivity_ files. 

# Introduction to Biopython  1

*Biopython* allows to ease the process of working with bioinformatic-related files and operations. This way, using *Biopython*, you will be able to use few functions to what otherwise, would have taken many more lines of code. In this document you will have an introduction to to *Biopython*'s basic classes and some of other resources along with a set of activities to help you get familiar with working with these tools.
 

### Key concepts

 - **SeqRecord object:** The `SeqRecord` object used in _Biopython_ to hold a sequence, as a `Seq` object, with identifiers `id` and `name`, `description` and optionally `annotation` and other sub-features. 
  <details>
    <summary>
        <span style="color: purple">Click here to display more information</span>
    </summary>
    <p>The <code>SeqRecord</code> object used in <em>Biopython</em> to hold a sequence, as a <a href="#Seq"><code>Seq</code></a> object, with identifiers <code>id</code> and <code>name</code>, description and optionally annotation and sub-features. The following table contains the <code>SeqRecord</code> attributes and the information they hold.</p>

    <blockquote>
            <table>
                <tr>
                   <td>.seq</td>
                   <td>Seq object containing a sequence</td>
                </tr>
                <tr>
                   <td>.id</td>
                   <td>Primary ID used to identify the sequence in a string format</td>
                </tr>
                <tr>
                   <td>.name</td>
                   <td> In some cases this will be the same as the accession number, but it could also be a clone name in a string a string format</td>
                </tr>
                <tr>
                   <td>.description</td>
                   <td>Brief description or expressive name for the sequence</td>
                </tr>
                <tr>
                   <td>.letter_annotations</td>
                   <td>
                   Dictionary of additional information about the letters in the sequence.
                   The keys are the name of the information (e.g. "phread_quality") and the value (as a list, tuple, string,...) has the same length as the
                   sequence itself (e.g. [40, 40, 38, 30, ...]).
                   </td>
                </tr>
                <tr>
                   <td>.annotations</td>
                   <td>
                    A dictionary of additional information about the sequence. The keys
                    are the name of the information, and the information is contained in
                    the value.
                   </td>
                </tr>
                 <tr>
                   <td>.features</td>
                   <td>
                   A list of SeqFeature objects with more structured information about the
                   features on a sequence (e.g. position of genes on a genome, or domains
                   on a protein sequence). See more on section 4.3 of the [documentation][docu].
                   </td>
                </tr>
                <tr>
                   <td>.dbxrefs</td>
                   <td>A list of database cross-references as strings (e.g. ['Project:58037']).</td>
                </tr>
             </table></blockquote>
    
    We will mainly be using the first 4 attributes. For example, the `example1.fa` file contains only two lines:
                
    >example1 this is a simple example<br>
    GATTACA-A
    
</details>



 - **Seq object:** The Seq attribute in the `SeqRecord` object is the minimum information needed to create an instance of this class. It consist on a sequence in the form of a `Python` `string` which offers many of the same methods along with additional ones. 
<details>
    <summary><span style="color: purple">Click here to display more information</span></summary>
    <p>The <code>Seq</code> attribute is the minimum information needed to create an instance of a <code>SeqRecord</code>. Like <code>SeqRecord</code>, the <code>Seq</code> object has its own set of attributes and its own module <code>Bio.Seq</code> which can be imported using <code>from Bio.Seq import Seq</code>.</p>
    <p>You need to keep in mind that like <code>Python</code> strings, <code>Seq</code> objects do not support item assignments and in order to modify them, we need to transform them into a <code>MutableSeq</code> object. To do this we need to import it using <code>from Bio.Seq import MutableSeq</code> and transform the <code>Seq</code> sequence through reassignment (e.g. <code>sequence = MutableSeq(sequence)</code>).</p>

</details>


 
Both of these objects are available in  their own module and can be imported using `from Bio.SeqRecord import SeqRecord` and `from Bio.Seq import Seq`.


------

### 1. Working with ` Bio.Seq` objects

As previously stated, the `Seq` object consist on a sequence in the form of a `Python` `string` which offers many of the same methods they have (e.g. `len()` and `count()`) alongs with additional methods like the `translate()`, `complement()` and `reverse_complement()`. The following command allows you to see an easy example showing how to create a `Seq` object instance and all the available attributes and methods available. You can find more information on the `Seq` methods under the section 3.1 to 3.8 of the [Biopython Documentation](http://biopython.org/DIST/docs/tutorial/Tutorial.pdf).


```python
from Bio.Seq import Seq

seq1 = Seq("GATTACA")

[print(att) for att in   dir(seq1)] 
```

    __add__
    __class__
    __contains__
    __delattr__
    __dict__
    __dir__
    __doc__
    __eq__
    __format__
    __ge__
    __getattribute__
    __getitem__
    __gt__
    __hash__
    __imul__
    __init__
    __init_subclass__
    __le__
    __len__
    __lt__
    __module__
    __mul__
    __ne__
    __new__
    __radd__
    __reduce__
    __reduce_ex__
    __repr__
    __rmul__
    __setattr__
    __sizeof__
    __str__
    __subclasshook__
    __weakref__
    _data
    back_transcribe
    complement
    complement_rna
    count
    count_overlap
    encode
    endswith
    find
    index
    join
    lower
    lstrip
    reverse_complement
    reverse_complement_rna
    rfind
    rindex
    rsplit
    rstrip
    split
    startswith
    strip
    tomutable
    transcribe
    translate
    ungap
    upper




Additionaly you can find the definition along with the arguments and examples by using help():


```python
## help(Seq.translate)
# help(Seq.find)
```

You can see below how some of these methods are implemented.  When executing the chunk, you will get a **warning** notifying you that the **string is not multiple of 3** and suggesting to either trim the sequence or adding trailing N before executing the `translate()` method. This is because otherwise, the **residual bases won't be accounted for** in this case,the obtained amino acids are DY since and residual A isn't accounted for. 


```python
print(seq1)
print("There are",seq1.count("A"), "Adenines")
print("The sequence is ",len(seq1), "bp long")
print(seq1.reverse_complement())
print(seq1.complement())
print(seq1.transcribe())
print(seq1.translate())
```

    GATTACA
    There are 3 Adenines
    The sequence is  7 bp long
    TGTAATC
    CTAATGT
    GAUUACA
    DY


    /home/alba/anaconda3/lib/python3.8/site-packages/Bio/Seq.py:2334: BiopythonWarning: Partial codon, len(sequence) not a multiple of three. Explicitly trim the sequence or add trailing N before translation. This may become an error in future.
      warnings.warn(


### <span style='color: blue'>Activity 1. PSUDOCODE EXERCISES</span>
    

Previously this week, we have introduced you to the following exercises. Our goal now is for you to use the available methods of the `Seq` objects to see first hand the advantages of **using _Biopython's Seq_** methods whenever you can. You can use the following `sequence` variables to test you codes, when it is the case, the best input will be specified. 


```python
seq2 = Seq("ATG-GATTACA-TGATTTT")
seq3 = Seq("ATGGCCGGGATTTGCTAG")
seq4 = Seq("STRESSED")
```

------

<span style='color: blue'> **Problem 1: DNA to RNA**: </span>
    
Write a code that given a DNA sequence in the form of a `Seq` object, outputs its RNA version. **Ignore start and stop codons**, simply exchange _Thymines_(T) by _Uracils_(U).

<blockquote>
Example: 

- Input: _GATTACA_
- Output: _GAUUACA_
</blockquote>


```python
# use Seq.transcribe()
print(seq1.transcribe(), seq2.transcribe(), sep="\n")
```

    GAUUACA
    AUG-GAUUACA-UGAUUUU


---------

<span style='color: blue'> **Problem 2: Find coding region**</span>

The reading frame starts whenever _ATG_ is encountered and it stops whenever _TAA, TAG, or TGA_ is encountered. Write code that given a DNA strand, finds the coding region not including the start and end codons. Note that if there is not start or no stop codon the function should return nothing (empty string). <span style='color: green'>Use seq2 and seq3</span>

<blockquote>
Example: 

-  Input: ATG-GATTACA-TGATTT
-  Output: -GATTACA-
</blockquote>


```python
#sol2.1

seq = seq2

start = seq.find("ATG") # get start pos
end = 0 # if no stop codon out will be empty

for pos in range(start+3, len(seq), 3): # for the rest of the sequence in steps of 3
    
    if seq[pos:pos+3] in ["TAA", "TAG", "TGA"]: # find a stop
        end = pos
        break

out = seq[start+3 : end] # resulting string excluding start and stop codons

print(out)
```

    -GATTACA-



```python
#sol2.2

seq = seq2 

start = seq.find("ATG")  # get start pos

# look for possible stops 
# if they are not in seq find() will return -1 and we will assign len(seq) + 1 
end1 = seq.find("TAA") if seq.find("TAA") != -1 else len(seq) + 1
end2 = seq.find("TGA") if seq.find("TGA") != -1 else len(seq) + 1
end3 = seq.find("TAG") if seq.find("TAG") != -1 else len(seq) + 1


end = min(end1, end2, end3) # get the smallest one

if (end-start % 3) == 0: # check correct reading frame
    out = seq[start+2:end] # get output string


print(out)

```

    -GATTACA-


------

<span style='color: blue'> **Problem 3: GC conten**</span>

The GC content is the percentage of _guanine_ (G) and _cytosine_ (C) nucleotides in a DNA or RNA molecule. Write a CODE than given a DNA or RNA strand it outputs its GC content **in percentage and one rounded decimal**.

<blockquote>
Example:

- Input: ATGGATTACATGATTT
- Output: _25.0%_
</blockquote>




```python
# use count()
seq =seq2

GC = (seq.count("G") + seq.count("C")) *100 /len(seq)

print(round(GC, 1), "%", sep ="")
```

    21.1%



<span style='color: green'> NOTE: You were supposed to solve this problem using `count()`, however, just so you know the _GC Content_ can also be computed by importing the module `GC` module from `Bio.SeqUtils` this way:<span> 

```python
from Bio.SeqUtils import GC

GC = GC(seq2)
print(GC)
```

-----

<span style='color: blue'> **Problem 4: Flip a string**<span>

We read words left to right. Write a code that given a word it flips it. It should output the word read from right to left.  <span style='color: green'> Use seq4 as a recomendation</span>

<blockquote>
    Example:

- Input: _STRESSED_
- Output: _DESSERTS_
</blockquote>


```python
# use reverse_complement() and complement()

seq = seq4

compl = seq.reverse_complement()

out =  compl.complement()

print(out)
```

    DESSERTS


-----

### Translation tables

`Seq` objects contain the translate() method which performs translation using an internal codon table objects derived from NCBI. We will only be importing the Standard table but there are many more, check the  [NCBI site for more information](#https://www.ncbi.nlm.nih.gov/Taxonomy/Utils/wprintgc.cgi).
We can import codon tables using `from Bio.Data import CodonTable`. 


```python
from Bio.Data import CodonTable

codons = CodonTable.unambiguous_dna_by_id[1]
print(codons, end = "\n\n")
print(codons.forward_table["ATG"])
print(codons.start_codons) #check that the standard code currently allows initiation
#                           from TTG and CTG in addition to ATG.
print(codons.stop_codons)
```

    Table 1 Standard, SGC0
    
      |  T      |  C      |  A      |  G      |
    --+---------+---------+---------+---------+--
    T | TTT F   | TCT S   | TAT Y   | TGT C   | T
    T | TTC F   | TCC S   | TAC Y   | TGC C   | C
    T | TTA L   | TCA S   | TAA Stop| TGA Stop| A
    T | TTG L(s)| TCG S   | TAG Stop| TGG W   | G
    --+---------+---------+---------+---------+--
    C | CTT L   | CCT P   | CAT H   | CGT R   | T
    C | CTC L   | CCC P   | CAC H   | CGC R   | C
    C | CTA L   | CCA P   | CAA Q   | CGA R   | A
    C | CTG L(s)| CCG P   | CAG Q   | CGG R   | G
    --+---------+---------+---------+---------+--
    A | ATT I   | ACT T   | AAT N   | AGT S   | T
    A | ATC I   | ACC T   | AAC N   | AGC S   | C
    A | ATA I   | ACA T   | AAA K   | AGA R   | A
    A | ATG M(s)| ACG T   | AAG K   | AGG R   | G
    --+---------+---------+---------+---------+--
    G | GTT V   | GCT A   | GAT D   | GGT G   | T
    G | GTC V   | GCC A   | GAC D   | GGC G   | C
    G | GTA V   | GCA A   | GAA E   | GGA G   | A
    G | GTG V   | GCG A   | GAG E   | GGG G   | G
    --+---------+---------+---------+---------+--
    
    M
    ['TTG', 'CTG', 'ATG']
    ['TAA', 'TAG', 'TGA']


#### Extra Activity

Use the `codons` variable to create a code that translates the sequence _"ATGGCCGGGATTTGCTAG"_. Check if it is correct by running: `Seq.translate(Seq("ATGGCCGGGATTTGCTAG"))`


```python
seq = Seq("ATGGCCGGGATTTGCTAG")
translated_seq = []

for pos  in range(0, len(seq), 3): # not exploring differnent reading frames
    
    codon = str(seq[pos:pos+3]) 
    
    if codon  == "ATG": # check for start
        inside = True # flag
    
    if inside: # inside coding region
        
        if codon in codons.stop_codons: #check for stop
            break 
        translated_seq.append(codons.forward_table[str(codon)]) #add current codon's aa
        
        
print("".join(translated_seq))
print(Seq.translate(seq))
```

    MAGIC
    MAGIC*


Additionally, we can also use `from Bio.Data import IUPACData` to import a dictionary to change the symbols of the amino acids from one to three (e.g. "G" to "Gly").

# Introduction to Biopython 2

### Key concepts

 - **SeqRecord object:** The `SeqRecord` object used in _Biopython_ to hold a sequence, as a `Seq` object, with identifiers `id` and `name`, `description` and optionally `annotation` and other sub-features. 
  <details>
    <summary>
        <span style="color: purple">Click here to display more information</span>
    </summary>
    <p>The <code>SeqRecord</code> object used in <em>Biopython</em> to hold a sequence, as a <a href="#Seq"><code>Seq</code></a> object, with identifiers <code>id</code> and <code>name</code>, description and optionally annotation and sub-features. The following table contains the <code>SeqRecord</code> attributes and the information they hold.</p>

    <blockquote>
            <table>
                <tr>
                   <td>.seq</td>
                   <td>Seq object containing a sequence</td>
                </tr>
                <tr>
                   <td>.id</td>
                   <td>Primary ID used to identify the sequence in a string format</td>
                </tr>
                <tr>
                   <td>.name</td>
                   <td> In some cases this will be the same as the accession number, but it could also be a clone name in a string a string format</td>
                </tr>
                <tr>
                   <td>.description</td>
                   <td>Brief description or expressive name for the sequence</td>
                </tr>
                <tr>
                   <td>.letter_annotations</td>
                   <td>
                   Dictionary of additional information about the letters in the sequence.
                   The keys are the name of the information (e.g. "phread_quality") and the value (as a list, tuple, string,...) has the same length as the
                   sequence itself (e.g. [40, 40, 38, 30, ...]).
                   </td>
                </tr>
                <tr>
                   <td>.annotations</td>
                   <td>
                    A dictionary of additional information about the sequence. The keys
                    are the name of the information, and the information is contained in
                    the value.
                   </td>
                </tr>
                 <tr>
                   <td>.features</td>
                   <td>
                   A list of SeqFeature objects with more structured information about the
                   features on a sequence (e.g. position of genes on a genome, or domains
                   on a protein sequence). See more on section 4.3 of the [documentation][docu].
                   </td>
                </tr>
                <tr>
                   <td>.dbxrefs</td>
                   <td>A list of database cross-references as strings (e.g. ['Project:58037']).</td>
                </tr>
             </table></blockquote>
    
    We will mainly be using the first 4 attributes. For example, the `example1.fa` file contains only two lines:
                
    >example1 this is a simple example<br>
    GATTACA-A
    
</details>



 - **Seq object:** The Seq attribute in the `SeqRecord` object is the minimum information needed to create an instance of this class. It consist on a sequence in the form of a `Python` `string` which offers many of the same methods along with additional ones. 
<details>
    <summary><span style="color: purple">Click here to display more information</span></summary>
    <p>The <code>Seq</code> attribute is the minimum information needed to create an instance of a <code>SeqRecord</code>. Like <code>SeqRecord</code>, the <code>Seq</code> object has its own set of attributes and its own module <code>Bio.Seq</code> which can be imported using <code>from Bio.Seq import Seq</code>.</p>
    <p>You need to keep in mind that like <code>Python</code> strings, <code>Seq</code> objects do not support item assignments and in order to modify them, we need to transform them into a <code>MutableSeq</code> object. To do this we need to import it using <code>from Bio.Seq import MutableSeq</code> and transform the <code>Seq</code> sequence through reassignment (e.g. <code>sequence = MutableSeq(sequence)</code>).</p>

</details>


 
Both of these objects are available in  their own module and can be imported using `from Bio.SeqRecord import SeqRecord` and `from Bio.Seq import Seq`.


----

### 2. Importing local files


If we wanted to manually import a sequence fasta file using `Python`, we would have to manually define the `ID/name` and read the rest of the file and store it as a sequence. The resulting function would look something like the following. 


```python
## Read fasta file python function:
def read_fasta(fastafile):
    
    with open(fastafile) as f_inp:
        lines = f_inp.readlines()
    
    seqs = [Seq("")]
    seqs[0].id = lines[0][1:].split()[0].strip() # 1st word after the ">"
    seqs[0].description = " ".join(lines[0][1:].split()[1:]) # rest of the line after id ">"
    seq = [] 
    i = 0
    for line in lines[1:]:
        if line.startswith('>'): #new sequence
            seqs[i].seq = ''.join(seq)
            seqs.append(Seq(""))
            i += 1
            seq = []
            seqs[i].id = lines[0][1:].split()[0].strip()
            seqs[i].description = " ".join(lines[0][1:].split()[1:])
        else:
            seq.append(line.strip()) # keep inputing sequence
    seqs[0].seq = ''.join(seq)
    return seqs

# Example
from Bio.Seq import Seq
seq = read_fasta('example1.fa')[0]
print(seq.id)
print(seq.description)
print(seq.seq)
```

    example0
    this is a simple example
    GATTACA-A


Then we would have to construct a specific function for each of the file formats. The `Bio.SeqIO` module allows a straightforward and uniform way for reading and writing sequence files in different formats, processing them as `SeqRecord` objects (view _Introduction to key concepts_ section).  The main function in `SeqIO` is **`Bio.SeqIO.parse()`**:
- **Input**: a **file's path** and **its format's name**.
- **Output**: an object or an iterator with objects of the `SeqRecord` class. 


```python
from Bio import SeqIO

record = SeqIO.parse("example1.fa", "fasta") # get record as SeqRecord

[print(att) for att in list(record)] # print all information
```

    ID: example0
    Name: example0
    Description: example0 this is a simple example
    Number of features: 0
    Seq('GATTACA-A')





    [None]



1. Files containing **a single record** can also be read using the function **`SeqIO.read()`** which takes same arguments as `SeqIO.parse()`. If there is more than one record in the file, an exception is raised.


```python
record = SeqIO.read("example1.fa", "fasta")
print(record)
```

    ID: example0
    Name: example0
    Description: example0 this is a simple example
    Number of features: 0
    Seq('GATTACA-A')


 2. If the file contains **several sequences**, we can store them in a list the following way.


```python
records = list(SeqIO.parse("example2.fa", "fasta"))

# to access the 1st SeqRecord in records:
print(records[0])
```

    ID: example1
    Name: example1
    Description: example1 this is simple example 1
    Number of features: 0
    Seq('THIS-IS-SEQUENCE-4')



```python
# to access all of the sequences of the document:
for rec in records:
    print(rec.seq, end= "\n\n")
```

    THIS-IS-SEQUENCE-4
    
    THIS-IS-SEQUENCE-1
    
    THIS-IS-SEQUENCE-3
    
    SOMETHING-IS-WRONG
    
    THIS-IS-SEQUENCE-2
    
    THIS-IS-SEQUENCE-1
    
    THIS-IS-SEQUENCE-6
    


### 3.  Modifying data

In the previous section, we demonstrated how to extract data from a `SeqRecord`. Once we have obtain the record, we can alter this data. 

1. The attributes of a SeqRecord can be modified directly:
```python
from Bio import SeqIO
record = SeqIO.parse("example1.fa", "fasta") 
record.id = "Gattaca"
```





```python
print("current Name is:", record.name, end = "\n\n")
record.name = "Gattaca" #change name
print("changed Name is:", record.name, end = "\n\n")

#print(record) # check all the attribute's content
record.name = "example0" #change name back
```

    current Name is: example0
    
    changed Name is: Gattaca
    



```python
# check what happens we try to alter the sequence's content
record.seq[3] = "A" 
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-7-7e9583a56ac3> in <module>
          1 # check what happens we try to alter the sequence's content
    ----> 2 record.seq[3] = "A"
    

    TypeError: 'Seq' object does not support item assignment


2. Transform them into a `MutableSeq`object.

In order to be able to only modify a specific position of a sequence we could turn them into a Python `list` then alter the postion and then use `.join()`to reassign the `.seq` content of record:



```python
recordlist = list(record.seq)
print(recordlist) # original
recordlist[-2] = "A"
print(recordlist, end="\n\n") # modified

record.seq = "".join(recordlist)
print(record)
```

    ['G', 'A', 'T', 'T', 'A', 'C', 'A', '-', 'A']
    ['G', 'A', 'T', 'T', 'A', 'C', 'A', 'A', 'A']
    
    ID: example0
    Name: example0
    Description: example0 this is a simple example
    Number of features: 0
    'GATTACAAA'


Alternatively, we can transform it into a `MutableSeq`object change it and use `.toseq()` when reassigning the variable to `record.seq`. To do this we need to import it
using `from Bio.Seq import MutableSeq`.


```python
from Bio.Seq import MutableSeq

mut_seq = MutableSeq(record.seq) # get mutable version

mut_seq[-2] = "-" # modify the sequence

record.seq = mut_seq.toseq()# back to a Seq object and reasign variable

print(record) # check all the attribute's content
```

    ID: example0
    Name: example0
    Description: example0 this is a simple example
    Number of features: 0
    Seq('GATTACA-A')


### <span style='color: blue'>Activity 2.  Modify a `Bio.Record` object</span>

1. Change the `.seq` sequence of the `SeqRecord` in the `record` variable containing the information in the file `example1.fa`  to be _"THIS-IS-SEQUENCE-0"_.   



```python
#solution
record.seq = Seq("".join(['THIS-IS-SEQUENCE-', record.id[-1]]))
print(record)
```

    ID: example0
    Name: example0
    Description: example0 this is a simple example
    Number of features: 0
    Seq('THIS-IS-SEQUENCE-0')


2. Do the same for the sequence of As you have seen the `example2.fa` file contains 7 records. The sequences should follow the pattern _"THIS-IS-SEQUENCE-#"_ (where "#" is 1, 2 and 3 respectively. Now change the `.seq` of the records 4 to 7 to follow the same pattern.     



```python
#[print(rec, end= "\n\n") for rec in records]
```


```python
#solution

for rec in records:
    rec.seq = Seq("".join(['THIS-IS-SEQUENCE-', rec.id[-1]]))

[print(rec, end= "\n"+"..."+"\n") for rec in records[0::3]]
```

    ID: example1
    Name: example1
    Description: example1 this is simple example 1
    Number of features: 0
    Seq('THIS-IS-SEQUENCE-4')
    ...
    ID: example4
    Name: example4
    Description: example4 this is simple example 4
    Number of features: 0
    Seq('THIS-IS-SEQUENCE-4')
    ...
    ID: example7
    Name: example7
    Description: example7 this is simple example 7
    Number of features: 0
    Seq('THIS-IS-SEQUENCE-7')
    ...





    [None, None, None]



------

## Exporting local files


You can use the `SeqIO.write()` function to output sequences files. This
function takes three arguments:
- A `SeqRecord` object or a list of them.
- A handle or filename to write to.
- The sequence format (e.g. _"fasta"_).

The following shows how this would work (see more on the
[activities][linkactivity]. In this case we are storing the list of records
_records_ into the output file _output_file.fa_ which will have a _fasta_ 
format.

```python
SeqIO.write(records, "output.fa" , "fasta")
```

This is the simple, straight-forward way, alternatively we can use 
`with open()`. The context manager (with statement) ensures that the file is properly closed after writing. 

```python
with open("output.fa", "w") as file_out:
    SeqIO.write(records, file_out, "fasta")
```

Both approaches achieve the same result, but using `with open()`
will allow you to perform additional operations. For example if the output file
isn't empty and your goal is to append the _records_ at the end of the file, 
you can easily achieve this by replacing the "w" in `open` by "a" (for append
mode). 


```python
with open("output.fa", "a") as file_out:
    SeqIO.write(records, file_out, "fasta")

```


### <span style='color: blue'>Activity 3. Exporting a file</span>

1. Using `SeqIO.write()` to create a new `fasta` file that contains the information of the modified `record` variable.  <span style='color: green'> Name the file *output_file.fa*</span>


```python

SeqIO.write(record, "output_file.fa" , "fasta") # the output is the number records saved

```




    1




2. Using `SeqIO.write()` to write at the end of the file, the content of the modified records of `example2.fa` stored in the `records` variable. Check your local directory to observe the resulting file 


```python
with open("output_file.fa", "a") as file_out:
    SeqIO.write(records, file_out, "fasta")
```

#### Extra

You can use existent files to create new files of different formats with the 
same content. You could read the file, using the `Bio.SeqIO.parse()` and pass
the `SeqRecord` iterator to the `Bio.SeqIO.write()` and save it using a 
different file format. However, `SeqIO` offers the `SeqIO.convert` function
which takes four arguments and does the this concisely. 

For example to turn a _GenBank_ file into a _Fasta_  file we can:

```python
from Bio import SeqIO
count = SeqIO.convert("output_file.fa", "fasta", "converted.txt", "tab")
```

# Introduction to Biopython 3

### Key concepts

 - **SeqRecord object:** The `SeqRecord` object used in _Biopython_ to hold a sequence, as a `Seq` object, with identifiers `id` and `name`, `description` and optionally `annotation` and other sub-features. 
  <details>
    <summary>
        <span style="color: purple">Click here to display more information</span>
    </summary>
    <p>The <code>SeqRecord</code> object used in <em>Biopython</em> to hold a sequence, as a <a href="#Seq"><code>Seq</code></a> object, with identifiers <code>id</code> and <code>name</code>, description and optionally annotation and sub-features. The following table contains the <code>SeqRecord</code> attributes and the information they hold.</p>

    <blockquote>
            <table>
                <tr>
                   <td>.seq</td>
                   <td>Seq object containing a sequence</td>
                </tr>
                <tr>
                   <td>.id</td>
                   <td>Primary ID used to identify the sequence in a string format</td>
                </tr>
                <tr>
                   <td>.name</td>
                   <td> In some cases this will be the same as the accession number, but it could also be a clone name in a string a string format</td>
                </tr>
                <tr>
                   <td>.description</td>
                   <td>Brief description or expressive name for the sequence</td>
                </tr>
                <tr>
                   <td>.letter_annotations</td>
                   <td>
                   Dictionary of additional information about the letters in the sequence.
                   The keys are the name of the information (e.g. "phread_quality") and the value (as a list, tuple, string,...) has the same length as the
                   sequence itself (e.g. [40, 40, 38, 30, ...]).
                   </td>
                </tr>
                <tr>
                   <td>.annotations</td>
                   <td>
                    A dictionary of additional information about the sequence. The keys
                    are the name of the information, and the information is contained in
                    the value.
                   </td>
                </tr>
                 <tr>
                   <td>.features</td>
                   <td>
                   A list of SeqFeature objects with more structured information about the
                   features on a sequence (e.g. position of genes on a genome, or domains
                   on a protein sequence). See more on section 4.3 of the [documentation][docu].
                   </td>
                </tr>
                <tr>
                   <td>.dbxrefs</td>
                   <td>A list of database cross-references as strings (e.g. ['Project:58037']).</td>
                </tr>
             </table></blockquote>
    
    We will mainly be using the first 4 attributes. For example, the `example1.fa` file contains only two lines:
                
    >example1 this is a simple example<br>
    GATTACA-A
    
</details>



 - **Seq object:** The Seq attribute in the `SeqRecord` object is the minimum information needed to create an instance of this class. It consist on a sequence in the form of a `Python` `string` which offers many of the same methods along with additional ones. 
<details>
    <summary><span style="color: purple">Click here to display more information</span></summary>
    <p>The <code>Seq</code> attribute is the minimum information needed to create an instance of a <code>SeqRecord</code>. Like <code>SeqRecord</code>, the <code>Seq</code> object has its own set of attributes and its own module <code>Bio.Seq</code> which can be imported using <code>from Bio.Seq import Seq</code>.</p>
    <p>You need to keep in mind that like <code>Python</code> strings, <code>Seq</code> objects do not support item assignments and in order to modify them, we need to transform them into a <code>MutableSeq</code> object. To do this we need to import it using <code>from Bio.Seq import MutableSeq</code> and transform the <code>Seq</code> sequence through reassignment (e.g. <code>sequence = MutableSeq(sequence)</code>).</p>

</details>


 
Both of these objects are available in  their own module and can be imported using `from Bio.SeqRecord import SeqRecord` and `from Bio.Seq import Seq`.


_____

## ENTREZ


We have seen how we can parse sequence data from a local file. Now we will see
how we can use a network connection to download and parse sequences from the
internet into a `SeqRecord` object. [_Entrez_](https://www.ncbi.nlm.nih.gov/Web/Search/entrezfs.html) is a data retrieval system that allows access to [_NCBI's_](https://www.ncbi.nlm.nih.gov/home/about/) databases. Currently it includes 38 databases
covering a variety of biomedical data.

_Biopython’s_ `Bio.Entrez` module allows you to search _PubMed_ or download
_GenBank_ records from within a Python script. The module uses _Entrez
Programming Utilities_ (EUtils) which consist on eight tools each of which
corresponds to a Python function. For example, out of  the eight available:


 - **`Entrez.esearch()`** allows you to get a list of ID's containing a specific
 term in a specific database.
 - **`Entrez.esummary()`** retrieves document summaries from a list of primary
 IDs.
 - **`Entrez.efetch()`** is used to retrieve a full record from _Entrez_ and
Requesting a specific file format.

<details>
    <summary>
        <span style="color: purple">display more information</span>
    </summary>
    There are another five <em>EUtils</em> functions described in sections 9.1 to 9.9 of <a href="http://biopython.org/DIST/docs/tutorial/Tutorial.pdf">Biopython's documentation</a>, and you can find more information on <a href="https://www.ncbi.nlm.nih.gov/books/NBK25501/">Entrez Programming Utilities on NCBI's page</a>. For now, just know that <em>EUtils</em> tools ensure that the correct URL is used for the queries, and that NCBI's guidelines for responsible data access are being followed.
</details>


A logical common pipeline to  import sequence files in this way would be the 
following.

1. Conduct a query using  `Entrez.egquery()` to get the and overview on amount of
IDs of a given term.
2. Use the module `Entrez.esearch()` and giving a selected database and the term
to retrieve the list of IDs of records that match a search term.

3. Use `Entrez.efetch()` to download the records we using the IDs we just 
obtained giving a specific file format. 

4. Finally use `Bio.SeqIO.parse()` to parse the data we downloaded into 
`SeqRecord` objects. 
</details>

As part of   [_NCBI’s Entrez User Requirements_](#https://www.ncbi.nlm.nih.gov/books/NBK25497/),   `Bio.Entrez` will require for you to probide an email address with each call to   _Entrez_. This  will be used only to contact developers if _NCBI_ observes requests that violate  policies prior to blocking access. 



```python
from Bio import Entrez
#Entrez.email = 'yourname.surname@alum.esci.upf.edu'
```

Use  Entrez.esearch() to retrieve the list of IDs of records that match a search of a given term from a selected database.


```python
with Entrez.esearch(db="nucleotide", term="5-hydroxytryptamine receptor") as search_handle:
    search_results = Entrez.read(search_handle)
[print(e, search_results[e]) for  e in search_results]
```

    Count 38694
    RetMax 20
    RetStart 0
    IdList ['2567554612', '2567525403', '2567525212', '2567521017', '2567516940', '2567516938', '2567516936', '2567516934', '2567516932', '2567513450', '2567507804', '2567507802', '2567507800', '2567504163', '2567504161', '2567504159', '2567504157', '2567502056', '2567497517', '2567497515']
    TranslationSet []
    TranslationStack [{'Term': '5-hydroxytryptamine[All Fields]', 'Field': 'All Fields', 'Count': '39151', 'Explode': 'N'}, {'Term': 'receptor[All Fields]', 'Field': 'All Fields', 'Count': '5339258', 'Explode': 'N'}, 'AND', 'GROUP']
    QueryTranslation 5-hydroxytryptamine[All Fields] AND receptor[All Fields]





    [None, None, None, None, None, None, None]




```python
list_of_ids = search_results["IdList"] #list of IDs
list_of_ids
```




    ['2567554612', '2567525403', '2567525212', '2567521017', '2567516940', '2567516938', '2567516936', '2567516934', '2567516932', '2567513450', '2567507804', '2567507802', '2567507800', '2567504163', '2567504161', '2567504159', '2567504157', '2567502056', '2567497517', '2567497515']



Use Entrez.efetch to download the records we using the IDs we just obtained giving a specific file format.


```python
with Entrez.efetch(db="nucleotide", id=list_of_ids, rettype="gb", retmode="text") as fetch_handle:
    data = fetch_handle.read()
data
```




    'LOCUS       XM_059156829            4029 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 2C\n            (HTR2C), mRNA.\nACCESSION   XM_059156829\nVERSION     XM_059156829.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081308) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..4029\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="X"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..4029\n                     /gene="HTR2C"\n                     /note="5-hydroxytryptamine receptor 2C; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 9 Proteins"\n                     /db_xref="GeneID:131821035"\n     CDS             1..1377\n                     /gene="HTR2C"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 2C"\n                     /protein_id="XP_059012812.1"\n                     /db_xref="GeneID:131821035"\n                     /translation="MVNLRKAVHSFLVHLIGLLVWQCDISVSPVAALVTDIFNTSDGG\n                     RFKFPDGVQNWPALSIVIIIILTIGGNILVIMAVSLEKKLHNATNYFLMSLAIADMLV\n                     GLLVMPLSLLAILYDYVWPLPRYLCPVWISLDVLFSTASIMHLCAISLDRYVAIRNPI\n                     EHSRFNSRTKAIMKIAIVWAISIGVSVPIPVIGLRDEEKVFVNNTTCVLNDPNFVLIG\n                     SFVAFFIPLTIMVITYCLTIYVLRRQALMLLHGHIEEPPGINWNFLKWCKRNAEEEEN\n                     PANPHQDGNPRRRKKKERRPRGTMQAINNERKASKVLGIVFFVFLVMWCPFFITNILS\n                     VLCGKACNQKLMEKLLNVFVWIGYVCSGINPLVYTLFNKIYRRAFSNYLRCNYKAEKK\n                     PPVRQMPRVAATALSGRELNVNIYRHTNEPVLKKADDSEPGIEMQVENLELPVNPSSV\n                     VSERISSV"\nORIGIN      \n        1 atggtgaacc tgaggaaagc ggtgcattcg ttccttgtgc acctaattgg cctactggtt\n       61 tggcaatgcg atatttctgt gagccctgtt gcagctctag taactgacat tttcaatacc\n      121 tccgatggtg gacgcttcaa attcccagac ggggtacaaa actggccagc actttcaatc\n      181 gtcattataa taatcttgac aataggtggc aacattctcg ttatcatggc agtaagcttg\n      241 gaaaagaaac tgcacaatgc caccaactat ttcttaatgt ccctagccat tgctgatatg\n      301 ctagtgggac tacttgtcat gccactgtct ctgcttgcaa tcctttatga ttatgtctgg\n      361 ccactaccta gatatttgtg ccccgtctgg atttctttgg atgttttatt ttctacagcg\n      421 tccatcatgc acctctgcgc tatctcgctg gatcggtatg tagcaatacg taatcctatt\n      481 gagcatagcc gtttcaattc gcggactaag gccatcatga agattgctat tgtttgggca\n      541 atttcgatag gtgtgtcagt tcctatccca gtgatcggac tgagagatga agagaaagtg\n      601 ttcgtcaaca acaccacctg cgtgctgaac gacccgaatt tcgttctcat tgggtccttc\n      661 gtcgcgttct tcatcccgtt aacgatcatg gtgattacgt actgcctgac gatctacgtt\n      721 cttcgccggc aagctctgat gttactgcac ggccacatcg aggaaccgcc tggaataaac\n      781 tggaactttc tgaagtggtg caagaggaac gctgaggagg aagagaatcc ggccaaccct\n      841 caccaggacg ggaacccacg ccgaaggaag aagaaagagc gacgccccag gggcaccatg\n      901 caagccatca acaatgaacg gaaagcgtcc aaagtgctcg gcattgtttt ctttgtgttt\n      961 ctggttatgt ggtgcccgtt tttcattacc aatattctgt cggttctgtg cgggaaggcc\n     1021 tgtaaccaaa agctcatgga aaagcttctg aatgtgtttg tttggattgg ctacgtctgt\n     1081 tcaggaatta accctctggt gtacacgctt ttcaacaaaa tttaccgaag ggctttctct\n     1141 aactatctgc gctgcaatta taaggcagaa aagaaacctc cggtgagaca gatgcccagg\n     1201 gtggccgcta ctgctttgtc agggagagag cttaacgtta acatttaccg gcataccaac\n     1261 gaacctgtgc ttaagaaagc tgatgacagt gagcccggta tagagatgca agtggagaat\n     1321 ttggagctcc cagttaatcc ctccagcgtg gttagtgaaa ggatcagcag tgtataatga\n     1381 gcagggtaca agcagcacag tctttcccta cggcaaagct acaaatgtag ggaaaggtct\n     1441 tagaattctt ctgtcggtca taactaatgt aaatatcgtc tgataaaaag tgttttgtat\n     1501 atagctttgc aaccctgtac tttacaatca tgcacacgac agtgagattt aggggtctat\n     1561 atttactgtt tataatagat ggagaataac ttattttgat tatttaatgc ataaaatgtt\n     1621 gatgtttcta ttatccctcc cttcctattt ccttccctcc ttctccctct ttctttcgtt\n     1681 ctctctctct ttccctctct ctttttcttt tgggcataag aaaatgttga tgttgatctc\n     1741 aggtggcatt tgcaggagac cagaatgacg cacgtgacag tggttatttc aaccacacca\n     1801 aaattaacga actcagtgga ctctttttcc gggttgacag taaatataca ctttaaattc\n     1861 ttgctctgct catctacaca cataaacaca gtaagatagg ttctgccttg tgatacctta\n     1921 tcacatgcat tggcgagtca aaggtagaac ttagcctcgt tgtcacatat aggggcaaaa\n     1981 tttgacattg tccggatgtc gtgttggtat tttactgcaa tgtccgtccc catagtggta\n     2041 ttttaacata gcagctggtt aaccaggact acagaagtgg aaggatgata cgagatatat\n     2101 acaccaatag cttttcactt cttaaggaca atgttcaaat tctgattatc acgacaagca\n     2161 aactggaatt agtgttttca ttctggtcct tagtaaatat ctaattctat gattaaactg\n     2221 gggaacaaga tcccagagtt atttcccaat ccaggattca acatcaattg ggttttgatc\n     2281 tcaggatcct ggaaattcgt gtgctacaca caaagtgaaa ttagcatttt gagccttatt\n     2341 aaaatatttt cataattatg gtacctctat ctataggacc caatttcgca gtccattttt\n     2401 gagtaaaact tgtgctggaa gcatagatga tcaaaacctt ggaagtttta cttgattaag\n     2461 gactacagaa ttaggccctt agaatgtgaa aaaaaaaaaa aaaagtaaaa acaagcttgt\n     2521 actgaactct gggaaaaaaa aaaaaaacag aaatacagag tttccatttg ggttttaaac\n     2581 aaaatttatc tcattttcag atccttccaa actctctagt gcaggaaaag gctgcagcta\n     2641 atttgtgaaa gtggcaagct cttcattgta ctgcaattat gtaccagaag tttaaaatct\n     2701 ttgttaaaat aatagtgttg tgtcacaata agtgttggcc attgtttcat tcgtgggcct\n     2761 gctgctctaa gaattcagta ccatttaact agtttgttaa ccacgaaagg ttttcaagca\n     2821 ttgctaaagt cagaccatga agtctatgct gtgtgccgag tatccaagtg ttgccactat\n     2881 ttccatgtgt gtccatttca cacaactgtg gatcaatttc tgaagaattc atgatgctat\n     2941 ctcttatgcc tgacagttac ttacacacct tagtgtgtgc ttctcaagat ctcgaaatcc\n     3001 gtgaaggcag aatctgaatt tcagagaacc cctggtctat gttctcaaca cacagcatag\n     3061 ataaatccaa cagtctgcca caggggcagt gggagagctg ctgtatttga ggaaactcat\n     3121 acagtctgtt tgattagcaa cactgccaaa tgtcagtcaa ttgcttgagc atgccccaat\n     3181 acaccatgaa agtcaagtct acctgcctgt tagctctgtt gaattgcatg ttaaaacaat\n     3241 tataggaaat tgaatgaaat gatctaattc ttactgaaac gaagacgtct gaagacacac\n     3301 agcatgcatt gagcatgagt tctgcacata cggatggagt cctgcatgta tgccatgtat\n     3361 gttgcatgaa tccatcgatt tgtattaacg taaggcagag tagatgatac aaaaaggact\n     3421 ggaggaaatc cttcagcagt ccttgagatg acacacattc agatctgaag tattgtgagt\n     3481 attagagaaa attggaaaca tctgatttct tttcttaact atcagggcaa gctcatagca\n     3541 catgttttac aaagaaataa aatataaacc acagattttg aaaagcacta gcaataagtg\n     3601 gaatgataat agcttatagc acatttgtta ataattctta tgtcatcaag tagtagtact\n     3661 taatagtacc caacacagta attattctca aatcgtgtgc tattcgtaag ttctgtgcag\n     3721 tttggtatga aacaaatata ctcatttgga tataaatctt acacttcaat gttaaatcta\n     3781 caaacttttg taaatgtttt aaaaagaaaa agtccatgtg ataaacgtaa acgtggtgaa\n     3841 tttactgtcg aacaaatcat tttgatgtac tattatatat gtatatctgt ttaagacacg\n     3901 tgcaacagac tgccttatat tatttcctgt aaatcttctc cttggtcaaa tggtactttt\n     3961 tgtgagtggt tgcaaagtgt tgtcttattt gtggttcctg tatgttatcc attccaagtt\n     4021 tttgtgata\n//\n\nLOCUS       XM_059177241            1835 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 1B\n            (HTR1B), mRNA.\nACCESSION   XM_059177241\nVERSION     XM_059177241.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081295) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..1835\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="6"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..1835\n                     /gene="HTR1B"\n                     /note="5-hydroxytryptamine receptor 1B; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 21 Proteins"\n                     /db_xref="GeneID:131833672"\n     CDS             5..1174\n                     /gene="HTR1B"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 1B"\n                     /protein_id="XP_059033224.1"\n                     /db_xref="GeneID:131833672"\n                     /translation="MEETGTRCAPPPPAGSQTGVPQANLSSNPHNCSAEGYIYQDSIA\n                     LPWKVLLVVLLALITLATTLSNAFVIATVYRTRKLHTPANYLIASLAVTDLLVSILVM\n                     PISTMYTVTGRWTLGQVVCDFWQSSDITCCTASILHLCVIALDRYWAITDAVEYSAKR\n                     TPKRAAVMIALVWVFSISISLPPFFWRQAKAEEEVSDCMVNTDHILYTVYSTVGAFYF\n                     PTLLLIALYGRIYVEARSRILKQTPNRTGKRLTRAQLITDSPGSTSSVTSVNSRAPDV\n                     PSESGSPVYVNQVKVRVSDALLEKKKLMAARERKATKTLGIILGAFIVCWLPFFIISL\n                     VMPICKDACWFHLAIFDFFTWLGYLNSLINPIIYTMSNEDFKQAFHKLIRFKCTG"\nORIGIN      \n        1 agacatggaa gaaaccggca ctcggtgcgc cccgccgccg cccgcgggct cccagaccgg\n       61 ggttcctcaa gccaatctct cctctaatcc ccacaactgc agcgccgagg gctacattta\n      121 ccaggactcc atcgccctgc cctggaaagt actactggtc gtgctgctgg cactcatcac\n      181 cttggccacc acgctctcca atgcttttgt gatcgccact gtgtaccgga cccggaagct\n      241 gcatacccca gccaactacc tgatcgcctc cctggcggtc accgacctgc tcgtatccat\n      301 cctggtgatg cccatcagca ccatgtacac ggtcaccggc cgctggacgc tgggccaggt\n      361 ggtctgcgac ttctggcagt cgtcggacat cacctgttgc actgcttcta tcctgcacct\n      421 ctgtgtcatc gccctggacc gctactgggc catcacggac gccgtggaat actcagctaa\n      481 aaggactccc aagagggccg cggtcatgat cgcgctggtg tgggtcttct ctatctccat\n      541 ctcgctgccg cccttcttct ggcgtcaagc caaagccgag gaagaggtgt cggactgcat\n      601 ggtgaacacc gaccacatcc tctataccgt ttactccacg gtgggcgctt tctacttccc\n      661 caccctgctc ctcatcgccc tctacggccg catctatgtg gaagcccgct cccggatttt\n      721 gaaacagacg cccaacagga ccggcaagcg cctgacccga gcccagctga taaccgactc\n      781 ccccgggtcc acgtcctcgg tcacctccgt taactcgcgg gctcccgatg tgcccagcga\n      841 atccgggtcc cccgtgtacg tgaaccaagt caaagtgcga gtctccgacg ccctgctaga\n      901 gaagaagaaa ctcatggccg ctagggagcg caaagccact aagaccctgg ggatcatact\n      961 gggagccttt attgtgtgct ggctgccctt cttcatcatc tccctagtga tgcctatttg\n     1021 caaggatgct tgctggttcc acctggccat ctttgacttc ttcacgtggc tgggctatct\n     1081 caactccctt atcaacccca tcatctatac catgtccaat gaggacttca aacaagcatt\n     1141 ccataaactg atacgcttta agtgcacagg ttgacttgtc agttgcaatg aggtagcctg\n     1201 agcggccttg ggggaccatg ttgggtctgg ttccacaggt aggtcgactc ttctttcact\n     1261 gttactgggt cggattgaga ctctgtcttc tgggcaaggg cagtggatcc tgagaagcca\n     1321 ggacagccct gagagagagc aagagctctg agagaactgt tcacactaaa ggtagagctt\n     1381 tcctgcaggg gaaggctcac ttcatcccct caaactccag gtccagccct gaccctgccg\n     1441 cagccagtca caggggaggg ttgtaacttt ttaaaaatca atgaaggaag ggggatcccc\n     1501 gccctgcttt ggtatcatgg atcatgccct ctagaaccag tggtacttgt agttgttgga\n     1561 agcctgtctg agacagatct acatacagcc tggcagtact tgaactagac gcataatacc\n     1621 ctttgttttg gggagaactt ttgtgttaca gcctcatttc agaagagtta ctttggcacc\n     1681 cttcagtctc cagtttttgt ttatttaaac ttggttggag aaacttgtgg atttggtgct\n     1741 tcaaacctta cgtgtggctt ggaggatgca gagaaacctt gaagagttaa cagcaaaatt\n     1801 ctgatgttaa tatctctatt tttattataa ttgaa\n//\n\nLOCUS       XM_059177143            5348 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 1E\n            (HTR1E), mRNA.\nACCESSION   XM_059177143\nVERSION     XM_059177143.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081295) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..5348\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="6"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..5348\n                     /gene="HTR1E"\n                     /note="5-hydroxytryptamine receptor 1E; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 6 Proteins"\n                     /db_xref="GeneID:131833626"\n     CDS             698..1795\n                     /gene="HTR1E"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 1E"\n                     /protein_id="XP_059033126.1"\n                     /db_xref="GeneID:131833626"\n                     /translation="MNITNCTTEASVAVRPKTITEKMLISMTLVIITTLTMLLNLAVI\n                     MAICTTKKLHQPANYLICSLAVTDLLVAVLVMPLSIMYIVMDSWKLGYFICEVWLSVD\n                     MTCCTCSILHLCVIALDRYWAITNAIEYARKRTAKRAVLMILTVWTISIFISMPPLFW\n                     RSHRQLSPPPSECTIQHDHVIYTIYSTLGAFYIPLTLILILYYRIYHAAKSLYQKRGS\n                     SRHLSNRSTDSQNSFASCKLTQTFCVSDFSTSDPTTEFEKIHNSIRIPSFDNDLDHPG\n                     ERQQISSTRERKAARILGLILGAFILSWLPFFIKELIVGLSIYTVSSEVADFLTWLGY\n                     VNSLINPLLYTSFNEDFKLAFKKLIKCREHV"\nORIGIN      \n        1 cggagctccg accctcgagt tgtcctccgc agccaccgcc cgcattgcac cccggctcac\n       61 cttttcgtcc ctcccacccc cttccccgtt cagtggcgtc ctgggtgcct gcaacctgcc\n      121 gggtgattca gtagactgcc ccctgctcct gttcttgttc ttgttcctgc tcctgctccg\n      181 gctcctgctc ctcctcctcc tccccctccc cgctctcgct ctcgcctcct cttccagtcg\n      241 gggcgcccag acttctccaa gcgcagcgcc acccggctgc ccagcgcgcc ccgctcctgg\n      301 ctccttctcg cggcagcctg ggggcaccgg cgcgggcaaa ggacgcttag gggccctcgc\n      361 cccctgagct cagcgtgccc cagagccgga tgttgagaga agctgtgctt tgataaagct\n      421 cgggagagca ccgagcgttt tcggagtgag acttcggcaa ccagcgggac gccccaggtc\n      481 acccagtgcg acgcggctgc acgcacggtc cacaaggagc cctcagaaga aatgatgtgg\n      541 tacttccttt tacccataca aaatggaaca taagaaacta catagctgaa gaaactacag\n      601 tcttcttata aatgagaggc attgaagtct aaataatttc cagctgaagg aaaataacca\n      661 acagcttctc tacagtgtag actgaaacag ggaaaacatg aatatcacta actgtaccac\n      721 agaagccagt gtggctgtga gacccaagac catcactgaa aagatgctca tctccatgac\n      781 tctggtgatc atcaccaccc tgaccatgtt actgaacttg gcggtgatca tggccatctg\n      841 taccaccaag aagctccacc agcctgccaa ctacctgatc tgttccctgg ctgtgacgga\n      901 tctcctggtg gcagtactcg ttatgccact gagcatcatg tacattgtca tggacagctg\n      961 gaaactagga tacttcatct gtgaggtgtg gctgagtgtg gacatgacct gctgcacctg\n     1021 ctccatcctc catctctgtg tgattgccct agacaggtac tgggccatca ccaatgctat\n     1081 tgaatatgcc aggaagagga ccgccaagag ggctgtgctg atgatcctca ccgtctggac\n     1141 catctccatc ttcatctcca tgccccccct cttctggaga agccaccgcc aactcagccc\n     1201 acctcctagt gagtgtacca tccagcatga ccatgtcatc tacaccattt attccacgct\n     1261 tggagcattt tatatcccct taactttgat acttattctg tattaccgga tctaccatgc\n     1321 agccaagagc ctttaccaga aaagaggatc aagccggcac ttaagcaaca gaagcacaga\n     1381 tagccaaaat tcttttgcga gttgtaaact tacacagact ttctgtgtgt ctgatttctc\n     1441 cacctcagac cctaccaccg agttcgaaaa gatccacaac tctatcagga tcccttcctt\n     1501 cgataatgat ctagatcacc caggagaacg tcagcagatc tctagtacca gggaacgcaa\n     1561 ggcagcacgc atcctaggac tgattttggg agcattcatt ttgtcgtggc ttccattttt\n     1621 catcaaagaa ttaattgtgg gtctgagtat ctacacagtg tcctctgaag tggctgattt\n     1681 tttaacgtgg cttggttatg ttaattctct gatcaaccct ctgctctata caagttttaa\n     1741 tgaagacttt aagctggctt ttaaaaagct aattaagtgc cgagaacatg tgtagatttc\n     1801 ataaagccaa aaggcattgt ttttaccagc cttgtttgtg gacagaggaa aggggttcaa\n     1861 cttattaatt cttgaacata gttggttcag aaaagtttgt aaggtactgt ggtccttttg\n     1921 tttgtttgtt tgtttgttct gttttgtttg aggtttgtta tctggtgtgc cgttttctac\n     1981 ctctggtttt atttgtggta catgatttcc aataaacatc ctataaagac agaaatttca\n     2041 tagacataat aataaggtga aatagtaact acttttttag ccatttcagt taatcttgca\n     2101 attaaagaac gccaaaataa atcttcattt gcagaatttc ttactactta taaatcaaat\n     2161 acttgataac ttgccctcct gtgccattaa aaccgaggtc gtggctccat atcatgcaaa\n     2221 ttttagaggg aactgcaaac tgcatgacta cataaagcat taatttaaaa aaaaagagtg\n     2281 gtgcactgtc atctgcttgc agacctgagc taaagtcatt tactgtgact acatagccca\n     2341 ctcctttagg cacaaatagt acagctgacg tgtcctttat agttcatgat taaatatgct\n     2401 tcctcattct ctaaaaagaa cctggaatga atactctggc actttcctag gtatttaact\n     2461 atgaaaatga aacaaaaaca aatacaagat aatctaaatc tcctccaatg tgttgttata\n     2521 tgacctgaca ggaacattgg acctccttac attctgagaa gagtcccgct gagccttgca\n     2581 cactctccct gactctggca ggatttgggt gggaatataa gcagcagacc ctctctctct\n     2641 tcctcccttc tcccctccct ttctcccatc cccctcctct cttctttaat ctcacttatc\n     2701 agtttgctca agtatcttga acactggcgt acatttcttc tactcctact tcccactcaa\n     2761 gagcctgctt cgtctctccg ctggctctcc cccctgagtt tctccactta tcaatccttc\n     2821 gttctgctca cctctcacct tccactgact ttcctatcct atgccatgtg agtttgtcac\n     2881 tcctagttct ctcgaaacag aactcccaga ggtctttggt gagttgccag taggcaaata\n     2941 caatggcctt gcctctgtcc ttatctactt tccaatctct catcaattaa aataactaag\n     3001 cctccctttt tcgttaagcc catgacttcc aaaatacaaa atacagtagt cccctgcttc\n     3061 tccaactacc tcctctttct ctgtctcctt ttctttctcc tggggtattg tcctcagctc\n     3121 ttacctcctg tatctccata ctctgtccca tcccatcaca tgcctgtggc ttttcaattt\n     3181 ttgtctttag ttctgatttg tctttctcaa attccagacc catgagttac ctccagtgaa\n     3241 cacctccctg tgactaacct gttcattcct caaacacagt ttttccatac tgaactcgtg\n     3301 atcattttcc cacactcaca ccttctcctc cttccacctt cccagtttca gataacagga\n     3361 ttaccttgcc tcttatcatc cctattagat aaacgtgatc ctctctcttc aagacttgtc\n     3421 tgtaacattc agagagtctt aaagtcttct ccatttacct ctacagaaat atgccccctt\n     3481 cttctccaat aagttggtcc cctcatctct tccaagtctt cttatctggt ccaccttcct\n     3541 ctggagtcct tcgcctgcaa ctccaccccc acacacctgc acatctatca gatacatctt\n     3601 ctagaacagt ggttttcaga gtggcagctc ccgaccagga acatttgcat cacctgggaa\n     3661 gttgtgaaaa atgcaatgtc ccgggctgaa gacataatga atcacagatt tggagagcaa\n     3721 aatctctgtt taataaaccc tctaggagat tctgatttga gaatcactac cctcaagcat\n     3781 accacaggtt ttaattataa tattcataat cctctactat ttctctatca gtttaaaata\n     3841 aattaagatt ccttagtata atattcaagg ctctttcact atgtgacttt aactaccttt\n     3901 ccagagttgt gactcaccac tttctctcac ccacctcata ctccagaaaa gtctggttat\n     3961 tttctgggtt ttctgagctc ccctaacagt agctcccaca gcttcagaaa actgacccca\n     4021 cggctttccc ttcttctacc agctcttcaa gcgatcttgc agcacaaatg caatctcctc\n     4081 tgtaaagtct ttccaagatc cttctttttc tttctccatc actatgaaaa ccctctctcc\n     4141 cagctctatg cttccataga accccatttc tatcactatt actatattca ccctatttta\n     4201 tagtgcattg tttatgtatt tctgctgtct gccctaatag actgtgagct ccttgagggc\n     4261 aggaaccatg tttattcatc tctgtatccc tagggacttc tacagtattt tgcacacagt\n     4321 agaccctcaa taaatgtaat gtgaatggaa ttatgtccct ggaaaagaaa atatcaatgt\n     4381 gccatcttct cccagtgaga aaaccaaact tctaaaatcc catggtacaa tactttcttt\n     4441 ttccccaaaa cttactccca cttcccaacc ttattcaaaa actgctggaa aaatcttcca\n     4501 cacggaaaga aaaaggattg tctgttgaat ataaatgaat aaactttaag caataggatt\n     4561 caagttaaga tgctctcaag aagggccccc ccaaacacag tagttcaaca agatagtttc\n     4621 tttctccctc acatgagagt aaagaggtag gagggcagcc tagagtgagt aggagactct\n     4681 gctgctcaac actatccagg acaaggtggt tcttccttcc tcccagggtt tgctctaatc\n     4741 tgcatggcca aagctgactc accatcacat ccacattcca gtccatagga agtaagagac\n     4801 agaagtagag agcagtttcc ttttaagcta tgtggggatc acataacttc tgcttgtact\n     4861 ccgttggcaa taatttgtca catggacaca ccaagttgta aaagagaata ggagagtaaa\n     4921 tctctagctg ggcacctcat gccttgctaa aattgaggac attataataa acagaagaac\n     4981 aagagaatga atacacagga acaatgaaca gtctacctca aagggatatt ggtttctgta\n     5041 tgtagagctc cggtatctca aggcaagtca attgctaccc agctcctgat gatctatgca\n     5101 tgaggatgtg gagatttaaa ttatgggtga ctggactgag attgtgcata tgctgaaaat\n     5161 acaatattta tcatgactgt acctctaata tttagaaatg atatgaacaa ctcacttgct\n     5221 ttctcatcat cttccacata tcatctattg aaaattcttg gtaattttaa gcattttaaa\n     5281 atgttaagag tctaagtaaa taaaaaacaa aaagcagatg cacaagtaat tttcacttac\n     5341 tcattttt\n//\n\nLOCUS       XM_059175083            4672 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 1A\n            (HTR1A), mRNA.\nACCESSION   XM_059175083\nVERSION     XM_059175083.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081294) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..4672\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="5"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..4672\n                     /gene="HTR1A"\n                     /note="5-hydroxytryptamine receptor 1A; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 17 Proteins"\n                     /db_xref="GeneID:131832279"\n     CDS             717..1985\n                     /gene="HTR1A"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 1A"\n                     /protein_id="XP_059031066.1"\n                     /db_xref="GeneID:131832279"\n                     /translation="MDVLNPGQGNNTTLSEGPFGTRGNATGISDVTFSYQVITSLLLG\n                     TLIFCAVLGNACVVAAIALERSLQNVANYLIGSLAVTDLMVSVLVLPMAALYQVLNKW\n                     TLGQVTCDLFIALDVLCCTSSILHLCAIALDRYWAITDPIDYVNKRTPRRAAALISLT\n                     WLIGFLISIPPMLGWRTPEDRSDPDACTISKDHGYTIYSTFGAFYIPLLLMLVLYGRI\n                     FRAARFRIRKTVKKVEKKGADTRFGVSPAPQPKKSMNGDPGSREWRQGVENKAVGTLC\n                     TNGAVRQGEDGAALEVIEVHRVGNSKEHLPLPSEAGAIPCTPASFEKKNERNAEAKRK\n                     MALARERKTVKTLGIIMGTFILCWLPFFIVALVLPFCESSCHMPTLLGAIINWLGYSN\n                     SLLNPVIYAYFNKDFQNAFKKIIKCKFCRR"\nORIGIN      \n        1 tctgcggacc aaaaggggct agaacgaaaa gacgctgatc tagtgggaga ggagggcggg\n       61 gacccagagg aaagagacac tcagggttgg ggaagtgtta ggaggggagg gttagcgtgg\n      121 gagggaggga cactctcaga gctgtgggag cgacgcaagg aaggataagg aaaggggagt\n      181 gagaagaaag agggagactg aagggggtgg ggagaaggct ttctagaaag gagacaggag\n      241 gagagagtgg aaaagggata gggagagaag caggaagagg agagtcagag tgaccttaga\n      301 ggatgaggct tctctattcc agatacttct aagattgaag actgttggct agtggggaga\n      361 ctccgactcc ggctccggca gccagttggg cagaggcaaa gtaaaatgga cagtgagaaa\n      421 cagatgttcc agccacctct ccaacgccca gaggtcccga agctcttttc tggcgaactc\n      481 cttccccagc tggagtctct gaggctgctg gaccaaggga gcccagggag cgcctggaag\n      541 ctgctcctcg gagatgccct cgcctgagca gtaagaactt cttgcttgag tccctgcatt\n      601 ccctccacct gaaactcccc aggagagagg ggtagaagac cccaggggga ggggcgaggg\n      661 gggatcctaa cgcagcactt tctcccctcc ccctcccccc cgccgggcgc gcaggcatgg\n      721 atgtgctcaa cccgggacag ggcaacaaca ccaccttgtc cgagggtccc ttcgggacac\n      781 gcggcaacgc tactggcatc tccgacgtga ccttcagcta ccaagtgatc acctcacttc\n      841 tgctgggcac gctcattttc tgcgcggtgc tgggcaatgc gtgcgtggtg gccgccatcg\n      901 ccctggagcg ctccctgcag aatgtggcca actatctcat cggctctttg gctgtcaccg\n      961 acctcatggt gtcggtgctg gtgctgccca tggctgcgct ctaccaggtg ctcaacaaat\n     1021 ggacgctggg gcaggtcacc tgtgacctat tcatcgccct cgacgtgctg tgttgcacct\n     1081 cgtccatcct gcacctgtgc gccattgcac tggacaggta ctgggccatc acggacccca\n     1141 ttgactacgt gaacaagagg acgccccggc gcgccgctgc gctcatctcg ctcacttggc\n     1201 ttattggctt ccttatctcc atcccgccca tgctgggttg gcgcaccccc gaagaccgct\n     1261 ccgaccccga cgcgtgcacg attagcaagg accacggcta cactatctac tccacctttg\n     1321 gcgctttcta catcccgctg ctgctcatgc tggttctcta cgggcgcatc ttccgagctg\n     1381 cgcgcttccg catccgcaaa acagtcaaga aggtggagaa gaagggagcg gacacccgct\n     1441 ttggggtgtc gccggccccg cagcccaaga agagcatgaa cggcgatccg gggagcagag\n     1501 aatggaggca gggtgtggag aacaaggcag tggggacttt gtgcaccaac ggcgcggtga\n     1561 ggcagggcga ggatggcgcc gcccttgagg tgattgaagt gcacagggtg ggcaactcca\n     1621 aagagcacct gccgctgccc agcgaggcgg gtgctatccc ttgcaccccc gcctccttcg\n     1681 agaagaagaa tgagcgcaac gccgaggcca agcgcaagat ggccctggcc cgggagagga\n     1741 aaacggtgaa gacgttgggc atcatcatgg gcacattcat cctctgctgg ctgccctttt\n     1801 tcatcgtggc cctggtcctg cccttctgtg agagcagctg ccacatgccc accctgctcg\n     1861 gagccataat caactggctg gggtactcca actctctgct caaccctgtc atttacgcct\n     1921 acttcaacaa agacttccaa aacgcgttta agaagatcat caagtgcaaa ttctgccgcc\n     1981 gatgatggtg gagtagtcgg cgagtaggcc cgccccatcc tctcttcctc ctccagtctt\n     2041 ctggaatcaa cacttctgat agctcgctaa tttcctctga ctttctccgc tgctcggggt\n     2101 ccccgcttcc agacctcgtc cctccacttc cgtcgcccaa taccctgctc gagggagtgc\n     2161 gctttgtgca aagagcccca gagagaggtc tggagggggt gggaaactcc ccgctccgtg\n     2221 ataagcgatc ttggctcagc ctttggcctc agaatcagtt ctgaactctg cacttgcctc\n     2281 ctccctcttc cgcaccccaa atcttcgcgg cggaagttta agcctaagcc attcaaggca\n     2341 aaaaaaaaaa aaaaaaaaaa aatctacaca gaaaaataaa cagtacatgc agccgccgcg\n     2401 cccactaacc gctcccacat gatcgcccca cagctagaac ttggatttaa ggttcaggag\n     2461 tttgcttcat tcccgatttc caaacctgcc ccgccatcct accctagaaa ctcacttttc\n     2521 ctccccagtt tcatgcctag gtttgctagt cgggaaaagc tggaaggtct gtttttccca\n     2581 gtgactgtgg tttccctggg aatccccgcc cccccgtgta gacttgcaga gtatctcttc\n     2641 cgcgcacagc ccctgctctg tcttccggga ctccaaacaa gtggccagaa gctgtctctt\n     2701 agagtgcact tgtaagtaca agcaaaactg ggccagtggg ggagagcgag gagggagtgc\n     2761 ggaacgattt ttatccgtgc ttgccttggc gtcagcactc accaaagaaa ctgacaatca\n     2821 gtggaaaggg aaaacagact tcggtttgta taggctcccc gcgcgtctgc acgttccggc\n     2881 gccgcgactt acctaccgcg ggctgtgccg accaacaagg cgtacgtgct caggcctccc\n     2941 ggccgcttac cagccccgcg cctccgcagc cagcggctgt gcggcttgcg ctcccggcgc\n     3001 gcgcgcaaga aagtctaccg aactaaagcc attcctccgt ttacgccgag gggcgcgcag\n     3061 aagggcggat aaaccacggg ggttgccgaa gccggagcta gctccggcgg gacaagcggg\n     3121 acccgggaag ccaaagaggg tggtgtcggg cgtttaagag ggaggagacg tcagtgcgcg\n     3181 cggccccggc tgcaggtggc gctcctcgtg gaacccgaaa gggcagtttc atccaaagga\n     3241 tgcagacttt cctcttagat acccctgtcc tttcggatag aatatttctg ttaagcgtgt\n     3301 cctaacatta aacgggattt gttctgtagg aagtctagca cacatagtta ccaggacttt\n     3361 gctttccaaa taggaattcc aggcttccaa tgagatgggt cccgataggc tttgtatgtg\n     3421 acctcacagg gagttacttt aaataatagg gccccaaaga ctagttaggg gtgctctcgc\n     3481 tgaggagttc ctgagactct tgtacagggt tattatgttt gctccttggc ctgatgtgag\n     3541 ccacaggtct aagacaaacc agtttcttgc catttaaata tatggagcac tccaagcttt\n     3601 ctcccccaca aaagttattc tttcaacctt gccacttctg ctgagaagcc agttagaatc\n     3661 tttactgccc ccagaaggga agttattttg gtgctccttt tgaatgtaaa tttccatcca\n     3721 caggactgga atcaagaggt gtgtaagtta gatgtagcct ctaattttct gatgactaac\n     3781 gtttgtgttt tccagtaatt gcacaaagtt attgattttt ctcttctctc ctttcaactg\n     3841 gaccttttga atgattgcgt cgctgttttg agaacagggt tgccaaagtt gccaatggaa\n     3901 tgttcacttg tgtttaggat taagaaggtg aaaagacagc actatcactg aagccatttt\n     3961 cttgtttgtc aacagaacaa agcctccgtt tgatatcttt ttctctaact gaaactaaga\n     4021 ataagcatca tatccagtta agatatagta gaactctgga cagtcagtgg ctggtttgtt\n     4081 catgcatatg taatgctgaa taagggacta aggtagactt cttaagtccg aaaattatta\n     4141 tttgaaaatt taatttcttt cttttttttc tttttctttc tttctttctt tttttttttt\n     4201 ttcttacaat aatttcagta cacctgtatg gaaaaaatgc acttttctgt gtgtcttcct\n     4261 taattttaga ttaaattata tatgtaaaat aattctagct caaaatttgt ttatccaact\n     4321 tatgccttgg ccagcaagtg ttatattcaa agtcttgagt cttccattta tttgtgtctc\n     4381 ttacagaact gtatgggaat ggcttttgga catttattct tcctactttg gaggaattac\n     4441 atgaaaatga ggaaggagca tccaattggg gtataattgc caaggcaata gagaaatttg\n     4501 gggaataagt gcatagcagt cagcagcccc tgatgctttt tatttctttt aatttttgta\n     4561 ttaagacaaa gtatatatat gtatcaaaat tgaccttcac ttttctctgt gacaataaag\n     4621 gacttcatta atggtaatgc tacaataaac tgatatcagt aacacatgca tc\n//\n\nLOCUS       XM_059173986            8447 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 4 (HTR4),\n            transcript variant X5, mRNA.\nACCESSION   XM_059173986\nVERSION     XM_059173986.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081294) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..8447\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="5"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..8447\n                     /gene="HTR4"\n                     /note="5-hydroxytryptamine receptor 4; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 9 Proteins"\n                     /db_xref="GeneID:131831742"\n     CDS             175..1338\n                     /gene="HTR4"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 4 isoform X4"\n                     /protein_id="XP_059029969.1"\n                     /db_xref="GeneID:131831742"\n                     /translation="MDEFDANVSSKEGFGSVEKVVLLTFLSAVILMAILGNLLVMVAV\n                     CRDRQLRKIKTNYFIVSLAFVDLLVSVLVMPFGAIELVQDIWIYGEMFCLVRTSLDVL\n                     LTTASIFHLCCISLDRYYAICCQPLVYRNKMTPLRIALMLGGCWVIPMFISFLPIMQG\n                     WNNIGIIDLIEKRKFNQNSNSTYCIFMVNKPYAITCSVVAFYIPFLLMVLAYYRIYVT\n                     AKEHAHQIQMLQRAGASSEGRPQPADQHSTHRMRTETKAAKTLCIIMGCFCLCWAPFF\n                     VTNIVDPFIDYTVPGQVWTAFLWLGYINSGLNPFLYAFLNKSFRRAFLIILCCDDERY\n                     RRPSILGQTVPCSTTTINGSTHVLRYTVLHSGHHQELEKLPIHNDPESLESCF"\nORIGIN      \n        1 cccgcagccg tcgcggtcgc ctctcccagg gcggggggcg gggtggggac cgccggggct\n       61 gggggcgtgg aacccgcgca gccctgcccc gctggccggg gagaaggacg atgcgcggcg\n      121 cgcccaggac cctgtgggca ctgagatcca actcacacat gcctatttcc tgtaatggat\n      181 gaatttgatg ctaatgtgag ttccaaggag ggttttgggt cagtggagaa ggtcgtgctg\n      241 ctcacgtttc tgtcagcggt tatcctgatg gccatcttgg ggaacctgct ggtgatggtg\n      301 gctgtgtgca gggacaggca gctcaggaag ataaaaacca attatttcat tgtctctctt\n      361 gccttcgtgg atctgctggt ttcggtgctg gtgatgccct ttggtgccat tgagctggtt\n      421 caagacatct ggatctatgg ggagatgttt tgcctcgttc ggacatctct agacgtcctg\n      481 ctcacgacgg catcaatttt tcacctgtgc tgcatttctc tggatcggta ttatgccatc\n      541 tgctgccagc ctctggtcta taggaacaag atgacccctc tgcgcatcgc attaatgctg\n      601 ggaggctgct gggtcatccc tatgtttatc tcttttctcc ctataatgca aggctggaat\n      661 aatattggca tcattgatct gatagaaaaa aggaagttca accagaactc taactctacg\n      721 tactgtatct tcatggtcaa caagccctac gccatcacct gctccgtggt ggccttctac\n      781 atcccgtttc tcctcatggt gctggcctat taccgcatct acgtcacagc gaaggagcac\n      841 gcccatcaga tccagatgtt acaacgggcc ggggcctcct cagaaggcag gccccagcca\n      901 gctgaccagc acagcactca tcgcatgagg acagagacca aagcagccaa gaccctgtgc\n      961 atcatcatgg gctgcttctg cctctgctgg gcaccattct ttgtcaccaa tatcgtggat\n     1021 cctttcatag actacaccgt tcctgggcag gtgtggaccg ctttcctctg gcttggctac\n     1081 atcaactctg ggttgaaccc ctttctctac gccttcttga ataagtcttt tagacgtgcc\n     1141 ttcctcatca tcctctgctg tgacgatgag cgctaccgaa gaccctccat cttgggccag\n     1201 actgtcccct gttcaaccac aaccattaat ggatccacac acgtgctaag gtacacagtt\n     1261 ctgcacagtg gacaccacca ggaacttgag aaactgccca tacacaatga cccagaatcc\n     1321 ttggaatcat gcttctgatt gagaacatgg ctcatgatta agccattcat tcccattcgt\n     1381 gtctgcatga acaggacacc ctggcatctc tcctgaccct catcaccacc cgtgaggcac\n     1441 gaggcagtgg ggccaagggc ccagggaaag tacatggagc gcagtgtggg agaggaccca\n     1501 aggccagaat atggaggatc ttggagttga ggagggactt caggcatccc cagatccagc\n     1561 ctcccatcca gtgcaggagt agcatcttcc atagcatccc tggaagtctg gtcagtctct\n     1621 gcttgcacac ctccaggggt agagctcact acctcctact gcagttcctt ctattgtagg\n     1681 gaatttttaa ttgtaagaaa gtttttccct ttcttgggac acaatcccgt ctctgctcca\n     1741 tcttgcattg gggccaatgc agttagctcc ctatcccctt tgagagcctc tagatattgg\n     1801 gagacgctga tctgccatct acgcaccctt ttaagtcttt tctccattct gaccacttcc\n     1861 tggacatact ttggtgggtg tatttatcaa ggcttttgta atgaaatcaa gttgatgcca\n     1921 acgccaagat gtctgtccag aagcactaca gagctgacaa gtgaaacttc agtattttct\n     1981 ggttgataga tgtgaacatt tgtctttttt cttggggata gttctggaaa ctgctcaggt\n     2041 tttgattttg gatccattat ccaaaggcat ctttactgtt cgtctaattt ctctgtgtgc\n     2101 ttaaagatga catttttctc atcggcatac cgggtctgag gtcatgtgga atgaagcttg\n     2161 atccactttc cttccatgac atgggaaaag gaacggcacc tttaccgaaa acactgctga\n     2221 aggatggtct ttggcgagga aattaagttg ctccaatgag acacatttca ggggttttct\n     2281 gggccctgtg ccaaggcagt gcttggtctc ggggcaggca ttttgctcac tggggcaaag\n     2341 acataatcac agaccactac tttctgggga aaattcactg gccccctgcc tgtgaagctg\n     2401 ctggggttcc atttttccac atctttttaa gcatctcact tcctccaagc tccttaggag\n     2461 atgctgcctt gatctcaaag ttaccggcaa atcatttcgt cttggggcga attatctccc\n     2521 caggttgaaa ctcttgaggg catatttttt ctggtagcct ttcttttgac tgctgataaa\n     2581 aatgctattg cgaagatgga ttgctggtcc ttagggaccc agcccagcaa aaaggcaatg\n     2641 tgggtgctgg gtggtggggg aggttacgaa atatagatgg gcccaaagtt tctagcctca\n     2701 ccagttctcc ttgcccttgt gttggatctg ttgaccccat tttccttcct aagtcatccc\n     2761 agaagccaca actgcctcct tatcacctgt tttatctgtg gaaggagaac ccactggctc\n     2821 tcccccttct ctctgtcctc agaaataatg ggaaggatga tcagacactc cactttttgt\n     2881 actgcaagtc ccaaatccca ggaatgctct cagttccagg caaaggaggc cggccggtca\n     2941 ccccacatag ggaccctccc agagaagatt aacaggccgc ctcatagctg cattttctct\n     3001 ctatactttt tcatggaaaa ggcagagctg agtgaattca ggtgtccagt tcttcccagg\n     3061 ctgtgtaaat gaggtctctg atctcaaagc acaaagaact tcttagggaa caactaagag\n     3121 atcataagaa ccagatcatc gtgaggagga ataggtttag tgctttgtgg caactggtaa\n     3181 gcttttctct cttaagtcga cagtacctgc tactgcctac gtagacgcac acacatgagc\n     3241 atacatccag taggattggt tccctacgaa atgcttcttt tcccaggagc ttggcaagct\n     3301 tatctaccag tgtaaaccat gatttctcgg aggtaagtct accatatcaa tggtaacttg\n     3361 gattcaacag ggacccacag aggacagtgc gcgtggaaaa atgagaactt cccatatcct\n     3421 caagccatca ccttctggac tctcgggaca tgtttctgtg ggtcagcacc tgattggtgt\n     3481 ctgcagaggt catgagcacc ctggacccat gaaacagcag cgactgagga aacggaagcc\n     3541 cttgccatca tcaagaagat ggtctctttt gtggagaagg tctcttcttc gctgtggctt\n     3601 tggaccgagg ctgggatgac gtggcgatgc acccaatagc cacgttggaa gtttatagga\n     3661 caggagcaga ggggctttgt ctggacagct gccagccggg catttctgag aggtctggct\n     3721 tcccagagtc ccagtaagag agcacgcgta tggaagactg agaaggagga gacgtagagt\n     3781 ttgtccaagg aaggaggaga ctcattctgc tatcttctcg gagaagacca ccctcttcca\n     3841 ggaagcccca ggtgtcaaga agagatgctt ccagggaggg gggcgtacgc ctcgggccac\n     3901 acctgccaca ccagcctgga caatcacagg ggtgacagtt gctgccacca gacaacccca\n     3961 cacgtgggat cgaggagcta cagctgtgct tcttcttaac ttgactctcc agctcacaga\n     4021 cctgggcagg tagaagccct gaactcccca tccagctcct ggtctgcagc tggaaagcaa\n     4081 aagaaatgct ccaaaccatc ttcttcaact gactcccaag tatgtgcttg tggacgaacc\n     4141 cgttcttcct ggatttcacc ttctcatctc acccccattt ccacttcaca ctgctcgctt\n     4201 gctctgtcct ggagcgagct gctgtccacc tgggagatgg ggggcgggag tgggctgtgg\n     4261 gtgggcgagg gaggggatcc agggagggac tgcgcgtggc tgtaacaaac ctgccttcaa\n     4321 tattgtcttc aaggaagaac gaagtaatgt tttcttggtg ctgtgctgtc tgcccgtttt\n     4381 tctccttggt gttgcatttc tttccgggga gaaagcagtg ttgcttttga ctttctgtta\n     4441 ctctgctgtg ctctggtcaa cgtccttcct tgtaacagct ggtcttgtgg gtggaaaaga\n     4501 ttaatacact taacttttct agctgtaatc tgcaatctct tcttcattca gtctagaaaa\n     4561 aaggctgagt gtatggctta aattttaaca aatcagggat gctcttgaag gcctgggttt\n     4621 gggttggcgt tcggctctag acttgaacca gctcgtgcct tgcttgtctc acccacaaaa\n     4681 caaagaaact ctctgagctg gtaggactgt tgggagtgtt ccaacagaca tccaagggcc\n     4741 cccgttagga ttattcccaa aagtgtgtcc tgcctaatat tgcgatttac ttaatatttt\n     4801 tcatagaagt caattcaagt tttcacttag ataaacattt tagagggaaa cattatattg\n     4861 atcccagaat agaaaatcag cattacttgc cataaataga aagcagccac agaggtaaat\n     4921 aaatgaaaac aaaacaaggt ttttaagttc taacttgagc ccagtgctca tgtgtttaaa\n     4981 agggaattga gtgctggacg acttggtggg aaggggggtg ccatgcccca cccgacaagg\n     5041 ggctcctgaa gctgggaagg gctgtgagga ttttggaggg gaacttccaa actttctgca\n     5101 tgaatgcggt taatcactag tggaattaga taccttttga aaccagagag agagggaaga\n     5161 cgaaactggt gatattttta attgctatta tatttgattc agatggcctc tcctttccct\n     5221 tcctcctttt tttttttttt taagttcacc cccgaacata tctaagttaa taataataat\n     5281 aattgtaata ataatgtagc aataataaga gaagctaaca tttaatgacc tcctttctgg\n     5341 taggcactgt ggtaaatgct ttacgtagat tatcttaatc ctcataaaat ccttacaaag\n     5401 taagtaccca aatctctccc acttagccgc agagcggacc tcagctgaga ggtctagccc\n     5461 aggccccagg gcgggaaggg tgtgtttgga gtgtggccgc agggggtgtg atggccaagc\n     5521 ccgcagtcct aatcgagggc acacggggct gagctcactc cgctctctcg tggagggcac\n     5581 ggtgctggga gagagcgtga gcaagcaggg gtggccctgc cctcctgttg cctaggaagt\n     5641 gcccttctgc ttcagcctgg ggcccagaca ggaatccggg acgcgcctgt tccagtgtgc\n     5701 agccctgccc cacacttgct ctagtgtcct ctttggctct ctttcacccc cgtgagcctc\n     5761 tctttgggtc tttaaacaag ggaggaatgc agtagatgat taatggggag gaaaggccct\n     5821 cctgcacgga tccttcctac tctctccagt attcagctgg caggctactg agtagccagc\n     5881 agcacaccct gaggatggac tgtgtgagcc cgagcgagcg ctgtcttgta tcccagagcc\n     5941 tacctggggt gcacaggtga ggagtggctc tagcggaggg taacttcact ttgccacact\n     6001 ttgttcgtgg ttggaacctg gaacactatc tggctaggct cttctgtccc aggagctcac\n     6061 cactgcgggc actttgtagt ttgttttcct gatgaggtcc ctgggcctct cacagtagcc\n     6121 tgcagggagg gattactgac agcttattct agaaaaggaa gcccacattg tcagggaagt\n     6181 tgatttgccc aaggacacag gagtcaggac cgaaacactg caggtcactc cattctacca\n     6241 gagtgctttc ctcctcttct ttaaattttt ttccaaatat acaaattatc tatttttaga\n     6301 cgacataaat gatgggttat ataatgggtt aggttacaca gataatgtat taacacagtc\n     6361 tgtccccacg atacaaagtt ctaactatgg gtagagcaaa acaccccttg actccagctt\n     6421 aatcccactc ccctccaggg aagtatgtgc tcttctacca atactgcatc ctagctccat\n     6481 atgtctaaat ggatggataa aaatatatgg tctcattttg ttcttatata taagtaacgc\n     6541 tctagagtat cacctgcaac ctgccttttt caactacacc atcaatgcca ttttggatca\n     6601 acacgtggga ctcttcgtcg tttgaggcca cacagcagat gctgtctgcc gtgcggagtt\n     6661 gtttctcctc tggtctggct gtataccggg tccgagcggg gcacgtgggg cccacatcgg\n     6721 aaaatcagca gcctccattt ttctgggact gtgctaacca ggtgaagggc ggccaaagta\n     6781 ggttagcgtt tatggggcag gtgccctgtg gagaaggccc atcctacctg ggtctctgct\n     6841 ggcttcccag ccccccttca agggactgag accctcttct ccaggggcac aggccctgca\n     6901 ggctgactga cagcatcctg cttctgctgg ttccctgatg cgtgcctttg acaaggtatt\n     6961 tagcttgctc aaccctgatt tccccagtgg taaagcaggg acggaatgat cagtcacact\n     7021 aataaagggt tagtatgagg atgtacgcaa agtacttggt aaaacttttt ttttttttta\n     7081 agattttatt tatttgacac agagagaaat cacaagtagg cagagaggca ggcagagaga\n     7141 gaggggagaa agcaggttcc ctgcagagca gagagcccga cgtggggctc gatcccagga\n     7201 ctctgggatc atgacctgag ccgaaggcag aggctttaac ccactgagcc acccaggtgc\n     7261 cctcttggta aaactttttt aaaaaaatat ctatttgaga gaatgcacac attgggtttg\n     7321 ggggatgggg aggcagagac tctaagtaga ctctccccac tgagtgtgga gcccaacaca\n     7381 ggggcttgat ctcacgatcc taagatcacc acctgagctg aaatcgagtc ggccactcaa\n     7441 cacttgaatc acccaggctc ccatggaaac acttttaaaa atgctctcat ggtatcatta\n     7501 cttcctctta atggcctcac cagctctctc tgcttccaac catcctggaa cagggtgaag\n     7561 gaacaggagg tgatggaaag agtaatagaa gcccctttcc taatgaaggg aattacagca\n     7621 gaggcactgt tttgtccctt tgtggcccat cttccatttt tggaggctca cccgccctgt\n     7681 ggggtgggcc cattattcct tgttaccggt tcacagctga ggaaacggag cccccagaat\n     7741 agaggctaca gccatcccca ggtcacccgg cagtcactga ggagttagga tctgaatcca\n     7801 ggtcttgagt ctcacagtgc agtctctgta ggagatgtgg gcctgctgcg ccctccagag\n     7861 gtcattccgg tcacagctgg cggcatccta agagacgagt atctccctga cattaattca\n     7921 gtcatccgtc tgcaacagtt cttacgtgac agacgctgca ctgcagattg gtgacatgcc\n     7981 attgcatggc tggatgggat aactctgttc tcggtggcag gtgtgggcaa gcacacggca\n     8041 gcctgggagc caagtcctcc agcctgcagg cacagtctct acttcttaaa gtggttggga\n     8101 aacaaaagat attttgtgac atgtggaaat tatgtgcaat ttaaatttgt gtccataaat\n     8161 aaagttggat cgtaacacgg ccacgtccgt ttgttgaagt acctctgtgg ctgcactccc\n     8221 actcccagcc gccgagggac ggccactggg gagctggaag taacatgctc tctggccccc\n     8281 gacagcaagt gggccgaccc ctgctgtgcg gcaatggctg tgcagccgtt cattctgcac\n     8341 acactgacca aatgcctcct acaggagtct tcttccaagt tcacggtttt gtttctcaga\n     8401 tgttctggtc tggacacctt cgcaatgatt ttagagctcc ctgctgt\n//\n\nLOCUS       XM_059173985            4877 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 4 (HTR4),\n            transcript variant X4, mRNA.\nACCESSION   XM_059173985\nVERSION     XM_059173985.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081294) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..4877\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="5"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..4877\n                     /gene="HTR4"\n                     /note="5-hydroxytryptamine receptor 4; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 15 Proteins"\n                     /db_xref="GeneID:131831742"\n     CDS             175..1341\n                     /gene="HTR4"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 4 isoform X3"\n                     /protein_id="XP_059029968.1"\n                     /db_xref="GeneID:131831742"\n                     /translation="MDEFDANVSSKEGFGSVEKVVLLTFLSAVILMAILGNLLVMVAV\n                     CRDRQLRKIKTNYFIVSLAFVDLLVSVLVMPFGAIELVQDIWIYGEMFCLVRTSLDVL\n                     LTTASIFHLCCISLDRYYAICCQPLVYRNKMTPLRIALMLGGCWVIPMFISFLPIMQG\n                     WNNIGIIDLIEKRKFNQNSNSTYCIFMVNKPYAITCSVVAFYIPFLLMVLAYYRIYVT\n                     AKEHAHQIQMLQRAGASSEGRPQPADQHSTHRMRTETKAAKTLCIIMGCFCLCWAPFF\n                     VTNIVDPFIDYTVPGQVWTAFLWLGYINSGLNPFLYAFLNKSFRRAFLIILCCDDERY\n                     RRPSILGQTVPCSTTTINGSTHVLRDAVECGGQWESHCHPPATSSLVAAQPGDP"\n     polyA_site      4877\n                     /gene="HTR4"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 cccgcagccg tcgcggtcgc ctctcccagg gcggggggcg gggtggggac cgccggggct\n       61 gggggcgtgg aacccgcgca gccctgcccc gctggccggg gagaaggacg atgcgcggcg\n      121 cgcccaggac cctgtgggca ctgagatcca actcacacat gcctatttcc tgtaatggat\n      181 gaatttgatg ctaatgtgag ttccaaggag ggttttgggt cagtggagaa ggtcgtgctg\n      241 ctcacgtttc tgtcagcggt tatcctgatg gccatcttgg ggaacctgct ggtgatggtg\n      301 gctgtgtgca gggacaggca gctcaggaag ataaaaacca attatttcat tgtctctctt\n      361 gccttcgtgg atctgctggt ttcggtgctg gtgatgccct ttggtgccat tgagctggtt\n      421 caagacatct ggatctatgg ggagatgttt tgcctcgttc ggacatctct agacgtcctg\n      481 ctcacgacgg catcaatttt tcacctgtgc tgcatttctc tggatcggta ttatgccatc\n      541 tgctgccagc ctctggtcta taggaacaag atgacccctc tgcgcatcgc attaatgctg\n      601 ggaggctgct gggtcatccc tatgtttatc tcttttctcc ctataatgca aggctggaat\n      661 aatattggca tcattgatct gatagaaaaa aggaagttca accagaactc taactctacg\n      721 tactgtatct tcatggtcaa caagccctac gccatcacct gctccgtggt ggccttctac\n      781 atcccgtttc tcctcatggt gctggcctat taccgcatct acgtcacagc gaaggagcac\n      841 gcccatcaga tccagatgtt acaacgggcc ggggcctcct cagaaggcag gccccagcca\n      901 gctgaccagc acagcactca tcgcatgagg acagagacca aagcagccaa gaccctgtgc\n      961 atcatcatgg gctgcttctg cctctgctgg gcaccattct ttgtcaccaa tatcgtggat\n     1021 cctttcatag actacaccgt tcctgggcag gtgtggaccg ctttcctctg gcttggctac\n     1081 atcaactctg ggttgaaccc ctttctctac gccttcttga ataagtcttt tagacgtgcc\n     1141 ttcctcatca tcctctgctg tgacgatgag cgctaccgaa gaccctccat cttgggccag\n     1201 actgtcccct gttcaaccac aaccattaat ggatccacac acgtgctaag ggatgcggtg\n     1261 gagtgtggtg gccaatggga gagtcactgc catcctccag caacttcttc tttggtggct\n     1321 gctcagcctg gtgaccctta gtccctgggg cggtgactca gaagacagcc atccctcgga\n     1381 gagagggcag attctaaact gctgcttgtg tgggaccgct cctgccattc tctccagcac\n     1441 gccttccgcc aggcagccgc gcccaccggg attttctctg gggctccagc aggtggcgct\n     1501 ggagggaccc aggggactgg aggcctcctc cttccctggg gtttctcttc cagagatcct\n     1561 ctacgaaggg attttttttt tttttttttc tttttccagc actccctctt cctggcgtct\n     1621 cgcccttgcg tcacactctc tgttgtcccc aatatgtccc cttactgttc ctggtttgtc\n     1681 tctcatgttc caaacaccat cgctcactgt gtcctatctc agtcatagat gtcttcaaat\n     1741 atgccttctt tgctgtgtct gcacacagac attgtcaaaa cacatcctcc tggtgcctgt\n     1801 cttggtcaga gccatgttcc aaaagcacac atttcttgct cattcacgcc tgttacaacc\n     1861 atgttcaaac tcctcgttgt cttatctctg tcctgttctg ggccagatcc tgttctgggc\n     1921 cagacgctaa tacactttct tcctggtgtt tgggtccaaa cctgcatcct cttggccagc\n     1981 ccccgtgtca gttgtagatc tcctgcccac tcttccttga ggccagttcc agtcctcttc\n     2041 aggatatgct ccatttactt accgtggaag aaatgggagc agagatctat ctgaaaacag\n     2101 tgtctgcggc agccttggag tttggccaga gacagcttcc cccagtgccg tggcctcggg\n     2161 ccctgctgct ccgagatgct tgcttccttc ttggactaga accggcatct tctgctgaag\n     2221 ggcctaaggc agggccaaca acattgtagt gttttttaaa gactttggaa tctttccctt\n     2281 gaacttgtgg caaaacccac agtagcagct taaaagcctt gaatctggcc ttgttgttcc\n     2341 caaaggaaag aactcttggc agctcacact ggggataagt gaacctcctc actgcacgtg\n     2401 gaggagggcc agactaagcc gtgtctgggg gggaacagag tgcttgactt gaagtcaagg\n     2461 accccgattc cagccctggc tctgctccta acatgctgtg agctcttggc ccatgctctt\n     2521 ccattcctgg acctcacttt ctacatctgt gaactgaagt tcagactccc agatctccaa\n     2581 gatccctttc tggttctagg accaaggata ctgctacatc cctcagctac ctcgaaaagc\n     2641 ccgtggcttg cctgcctttt gactttgttt caaaggaatc accctcctca tttgggcctt\n     2701 ctagactctt gatcttgcca actttgtcct tcgaattaac caggaagtct tttagtcgaa\n     2761 gctgaggtcc ttggctctta ccaactgccc cagagtaaaa gtcccaggga actagacacc\n     2821 gccatgtcct agagccatgt aaggttctaa cagtgatcct ggctgggatt tgatcgcatc\n     2881 tcaggacttt atcatactca ttgttcctgc tgcttaaaag atgtcagtta ccatttccac\n     2941 tgatgttgac tttggttctg gaattgaacc ggaaaggaaa gagactgaaa taaggaagaa\n     3001 aagattgtcc tcaaaccatc taaatgccag aacaaaacaa aacaaaaccc cacaaaaccc\n     3061 aaaaacaaaa caaaacaaaa taacaaaacc caaaacaaaa caaaaaaacc ctctgtcctg\n     3121 caaaagctta attttgttgg ggagaaagtc acaccttagg gaagggaaaa agcctctaaa\n     3181 gacaaatgtt atttagtact cctgaatgca gttgagactt acggcaacgt gctgaaacgt\n     3241 tccctgtcta ggctggaacc ctcactgatc agattgaaga tctgattgaa ctggagatct\n     3301 agcctcatcc aggacaaaga gagtttacgt gagtcctaat gggcaccttg actctggctg\n     3361 gaccaatttc ttttgctttt tcaagtccct gtttgctgac tgcattcagg cttaggcgac\n     3421 tgccatcatc ttgaggatgg ttctttctta atacaaggga ggcagcaaca aggttctgag\n     3481 gcccaaggtc ctgaagtcag caatgggccc caaactctct gctcggcttg acatgctacc\n     3541 cgttgcctct gtgagcgcga gggagagatg gctgtggtag agaagcgcca tgctgactct\n     3601 cgctgtgtga ccttcaacct ctctggcctt gaaagaatcc ctcttggcta cttcgcaaag\n     3661 ttgttgtgga gataaaaaag ataatttttg tgaaaacatc ctgtaaatca taaaatgcta\n     3721 ttttgtatgt ttatccttac tttggattac tttggatgct cctgaatgcc caaggacaaa\n     3781 gaatttcctc accaagatgt gaaccagttt agagaatgag cttcccatgt tgaaaaacca\n     3841 taccaaggga gcacctttca gggtttcttt cttccaaatc cacccctcct cgtttggtta\n     3901 ccgcacacac ccacactgca aatttataca gcagaaacat tctcatttga agggatattg\n     3961 ttattcttaa aggagtcggt ggagggagat ggtgaccaca ggctaatttg gtaataatga\n     4021 gccttgattt catgaaacgt caaagtcaca tgacaaaaat tcacatgccc gtttgtcgtg\n     4081 caaacattta ttttgagaat aaagacctgg gtcatcgaaa tgatccccac tttgtaactg\n     4141 ttataaatat atatatatat atatatatat atatatatat acatataaat tctgtgcaaa\n     4201 taaaaaactc aaacatggat tatttatgaa cgagcagctg acaagactgt tacaggaaga\n     4261 atctactgag ctactgaacc agataattct aaaaaatgtt ttctaatctg atagccatgt\n     4321 aaactattgt taattatggt ttaatattat ttaggcacca cctaaatttt gtttacattt\n     4381 tcaataaagt agaattagag tggggccact cctacagttt ataatgcact aagtgtcctg\n     4441 tataatcaac atgtaatgta catatgtgcc tgttatagag aatatggaat ttaattatat\n     4501 aattttaaag gattgcaaat tttagtgatg gttgtatctt tggttttatg agattattag\n     4561 ttacatctgt gatttattgg aggctaaagc tttgaaggta ctggggtccc tcaatctaat\n     4621 ttgtctctct ggaaaacact cttgagttta cctgctcttg atactgttcc caggaatgca\n     4681 ttctgggaaa aacaggaact aacatagtct ttcttttgta atagataaat tctatttatt\n     4741 gataaatatt tgataaattc cacatctgtt tatatttatg cattctgtac atgtttatat\n     4801 aaattacata tttagggaaa tcttaagtct caaaattaat aactgaattt tgaaacacaa\n     4861 taaaatgcca aagtcaa\n//\n\nLOCUS       XM_059173984            8489 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 4 (HTR4),\n            transcript variant X3, mRNA.\nACCESSION   XM_059173984\nVERSION     XM_059173984.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081294) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..8489\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="5"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..8489\n                     /gene="HTR4"\n                     /note="5-hydroxytryptamine receptor 4; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 2 Proteins"\n                     /db_xref="GeneID:131831742"\n     CDS             175..1380\n                     /gene="HTR4"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 4 isoform X2"\n                     /protein_id="XP_059029967.1"\n                     /db_xref="GeneID:131831742"\n                     /translation="MDEFDANVSSKEGFGSVEKVVLLTFLSAVILMAILGNLLVMVAV\n                     CRDRQLRKIKTNYFIVSLAFVDLLVSVLVMPFGAIELVQDIWIYGEMFCLVRTSLDVL\n                     LTTASIFHLCCISLDRYYAICCQPLVYRNKMTPLRIALMLGGCWVIPMFISFLPIMQG\n                     WNNIGIIDLERISKPRLGQDLHVIEKRKFNQNSNSTYCIFMVNKPYAITCSVVAFYIP\n                     FLLMVLAYYRIYVTAKEHAHQIQMLQRAGASSEGRPQPADQHSTHRMRTETKAAKTLC\n                     IIMGCFCLCWAPFFVTNIVDPFIDYTVPGQVWTAFLWLGYINSGLNPFLYAFLNKSFR\n                     RAFLIILCCDDERYRRPSILGQTVPCSTTTINGSTHVLRYTVLHSGHHQELEKLPIHN\n                     DPESLESCF"\nORIGIN      \n        1 cccgcagccg tcgcggtcgc ctctcccagg gcggggggcg gggtggggac cgccggggct\n       61 gggggcgtgg aacccgcgca gccctgcccc gctggccggg gagaaggacg atgcgcggcg\n      121 cgcccaggac cctgtgggca ctgagatcca actcacacat gcctatttcc tgtaatggat\n      181 gaatttgatg ctaatgtgag ttccaaggag ggttttgggt cagtggagaa ggtcgtgctg\n      241 ctcacgtttc tgtcagcggt tatcctgatg gccatcttgg ggaacctgct ggtgatggtg\n      301 gctgtgtgca gggacaggca gctcaggaag ataaaaacca attatttcat tgtctctctt\n      361 gccttcgtgg atctgctggt ttcggtgctg gtgatgccct ttggtgccat tgagctggtt\n      421 caagacatct ggatctatgg ggagatgttt tgcctcgttc ggacatctct agacgtcctg\n      481 ctcacgacgg catcaatttt tcacctgtgc tgcatttctc tggatcggta ttatgccatc\n      541 tgctgccagc ctctggtcta taggaacaag atgacccctc tgcgcatcgc attaatgctg\n      601 ggaggctgct gggtcatccc tatgtttatc tcttttctcc ctataatgca aggctggaat\n      661 aatattggca tcattgatct ggagaggata tccaagccaa ggctgggcca ggatttgcat\n      721 gtgatagaaa aaaggaagtt caaccagaac tctaactcta cgtactgtat cttcatggtc\n      781 aacaagccct acgccatcac ctgctccgtg gtggccttct acatcccgtt tctcctcatg\n      841 gtgctggcct attaccgcat ctacgtcaca gcgaaggagc acgcccatca gatccagatg\n      901 ttacaacggg ccggggcctc ctcagaaggc aggccccagc cagctgacca gcacagcact\n      961 catcgcatga ggacagagac caaagcagcc aagaccctgt gcatcatcat gggctgcttc\n     1021 tgcctctgct gggcaccatt ctttgtcacc aatatcgtgg atcctttcat agactacacc\n     1081 gttcctgggc aggtgtggac cgctttcctc tggcttggct acatcaactc tgggttgaac\n     1141 ccctttctct acgccttctt gaataagtct tttagacgtg ccttcctcat catcctctgc\n     1201 tgtgacgatg agcgctaccg aagaccctcc atcttgggcc agactgtccc ctgttcaacc\n     1261 acaaccatta atggatccac acacgtgcta aggtacacag ttctgcacag tggacaccac\n     1321 caggaacttg agaaactgcc catacacaat gacccagaat ccttggaatc atgcttctga\n     1381 ttgagaacat ggctcatgat taagccattc attcccattc gtgtctgcat gaacaggaca\n     1441 ccctggcatc tctcctgacc ctcatcacca cccgtgaggc acgaggcagt ggggccaagg\n     1501 gcccagggaa agtacatgga gcgcagtgtg ggagaggacc caaggccaga atatggagga\n     1561 tcttggagtt gaggagggac ttcaggcatc cccagatcca gcctcccatc cagtgcagga\n     1621 gtagcatctt ccatagcatc cctggaagtc tggtcagtct ctgcttgcac acctccaggg\n     1681 gtagagctca ctacctccta ctgcagttcc ttctattgta gggaattttt aattgtaaga\n     1741 aagtttttcc ctttcttggg acacaatccc gtctctgctc catcttgcat tggggccaat\n     1801 gcagttagct ccctatcccc tttgagagcc tctagatatt gggagacgct gatctgccat\n     1861 ctacgcaccc ttttaagtct tttctccatt ctgaccactt cctggacata ctttggtggg\n     1921 tgtatttatc aaggcttttg taatgaaatc aagttgatgc caacgccaag atgtctgtcc\n     1981 agaagcacta cagagctgac aagtgaaact tcagtatttt ctggttgata gatgtgaaca\n     2041 tttgtctttt ttcttgggga tagttctgga aactgctcag gttttgattt tggatccatt\n     2101 atccaaaggc atctttactg ttcgtctaat ttctctgtgt gcttaaagat gacatttttc\n     2161 tcatcggcat accgggtctg aggtcatgtg gaatgaagct tgatccactt tccttccatg\n     2221 acatgggaaa aggaacggca cctttaccga aaacactgct gaaggatggt ctttggcgag\n     2281 gaaattaagt tgctccaatg agacacattt caggggtttt ctgggccctg tgccaaggca\n     2341 gtgcttggtc tcggggcagg cattttgctc actggggcaa agacataatc acagaccact\n     2401 actttctggg gaaaattcac tggccccctg cctgtgaagc tgctggggtt ccatttttcc\n     2461 acatcttttt aagcatctca cttcctccaa gctccttagg agatgctgcc ttgatctcaa\n     2521 agttaccggc aaatcatttc gtcttggggc gaattatctc cccaggttga aactcttgag\n     2581 ggcatatttt ttctggtagc ctttcttttg actgctgata aaaatgctat tgcgaagatg\n     2641 gattgctggt ccttagggac ccagcccagc aaaaaggcaa tgtgggtgct gggtggtggg\n     2701 ggaggttacg aaatatagat gggcccaaag tttctagcct caccagttct ccttgccctt\n     2761 gtgttggatc tgttgacccc attttccttc ctaagtcatc ccagaagcca caactgcctc\n     2821 cttatcacct gttttatctg tggaaggaga acccactggc tctccccctt ctctctgtcc\n     2881 tcagaaataa tgggaaggat gatcagacac tccacttttt gtactgcaag tcccaaatcc\n     2941 caggaatgct ctcagttcca ggcaaaggag gccggccggt caccccacat agggaccctc\n     3001 ccagagaaga ttaacaggcc gcctcatagc tgcattttct ctctatactt tttcatggaa\n     3061 aaggcagagc tgagtgaatt caggtgtcca gttcttccca ggctgtgtaa atgaggtctc\n     3121 tgatctcaaa gcacaaagaa cttcttaggg aacaactaag agatcataag aaccagatca\n     3181 tcgtgaggag gaataggttt agtgctttgt ggcaactggt aagcttttct ctcttaagtc\n     3241 gacagtacct gctactgcct acgtagacgc acacacatga gcatacatcc agtaggattg\n     3301 gttccctacg aaatgcttct tttcccagga gcttggcaag cttatctacc agtgtaaacc\n     3361 atgatttctc ggaggtaagt ctaccatatc aatggtaact tggattcaac agggacccac\n     3421 agaggacagt gcgcgtggaa aaatgagaac ttcccatatc ctcaagccat caccttctgg\n     3481 actctcggga catgtttctg tgggtcagca cctgattggt gtctgcagag gtcatgagca\n     3541 ccctggaccc atgaaacagc agcgactgag gaaacggaag cccttgccat catcaagaag\n     3601 atggtctctt ttgtggagaa ggtctcttct tcgctgtggc tttggaccga ggctgggatg\n     3661 acgtggcgat gcacccaata gccacgttgg aagtttatag gacaggagca gaggggcttt\n     3721 gtctggacag ctgccagccg ggcatttctg agaggtctgg cttcccagag tcccagtaag\n     3781 agagcacgcg tatggaagac tgagaaggag gagacgtaga gtttgtccaa ggaaggagga\n     3841 gactcattct gctatcttct cggagaagac caccctcttc caggaagccc caggtgtcaa\n     3901 gaagagatgc ttccagggag gggggcgtac gcctcgggcc acacctgcca caccagcctg\n     3961 gacaatcaca ggggtgacag ttgctgccac cagacaaccc cacacgtggg atcgaggagc\n     4021 tacagctgtg cttcttctta acttgactct ccagctcaca gacctgggca ggtagaagcc\n     4081 ctgaactccc catccagctc ctggtctgca gctggaaagc aaaagaaatg ctccaaacca\n     4141 tcttcttcaa ctgactccca agtatgtgct tgtggacgaa cccgttcttc ctggatttca\n     4201 ccttctcatc tcacccccat ttccacttca cactgctcgc ttgctctgtc ctggagcgag\n     4261 ctgctgtcca cctgggagat ggggggcggg agtgggctgt gggtgggcga gggaggggat\n     4321 ccagggaggg actgcgcgtg gctgtaacaa acctgccttc aatattgtct tcaaggaaga\n     4381 acgaagtaat gttttcttgg tgctgtgctg tctgcccgtt tttctccttg gtgttgcatt\n     4441 tctttccggg gagaaagcag tgttgctttt gactttctgt tactctgctg tgctctggtc\n     4501 aacgtccttc cttgtaacag ctggtcttgt gggtggaaaa gattaataca cttaactttt\n     4561 ctagctgtaa tctgcaatct cttcttcatt cagtctagaa aaaaggctga gtgtatggct\n     4621 taaattttaa caaatcaggg atgctcttga aggcctgggt ttgggttggc gttcggctct\n     4681 agacttgaac cagctcgtgc cttgcttgtc tcacccacaa aacaaagaaa ctctctgagc\n     4741 tggtaggact gttgggagtg ttccaacaga catccaaggg cccccgttag gattattccc\n     4801 aaaagtgtgt cctgcctaat attgcgattt acttaatatt tttcatagaa gtcaattcaa\n     4861 gttttcactt agataaacat tttagaggga aacattatat tgatcccaga atagaaaatc\n     4921 agcattactt gccataaata gaaagcagcc acagaggtaa ataaatgaaa acaaaacaag\n     4981 gtttttaagt tctaacttga gcccagtgct catgtgttta aaagggaatt gagtgctgga\n     5041 cgacttggtg ggaagggggg tgccatgccc cacccgacaa ggggctcctg aagctgggaa\n     5101 gggctgtgag gattttggag gggaacttcc aaactttctg catgaatgcg gttaatcact\n     5161 agtggaatta gatacctttt gaaaccagag agagagggaa gacgaaactg gtgatatttt\n     5221 taattgctat tatatttgat tcagatggcc tctcctttcc cttcctcctt tttttttttt\n     5281 tttaagttca cccccgaaca tatctaagtt aataataata ataattgtaa taataatgta\n     5341 gcaataataa gagaagctaa catttaatga cctcctttct ggtaggcact gtggtaaatg\n     5401 ctttacgtag attatcttaa tcctcataaa atccttacaa agtaagtacc caaatctctc\n     5461 ccacttagcc gcagagcgga cctcagctga gaggtctagc ccaggcccca gggcgggaag\n     5521 ggtgtgtttg gagtgtggcc gcagggggtg tgatggccaa gcccgcagtc ctaatcgagg\n     5581 gcacacgggg ctgagctcac tccgctctct cgtggagggc acggtgctgg gagagagcgt\n     5641 gagcaagcag gggtggccct gccctcctgt tgcctaggaa gtgcccttct gcttcagcct\n     5701 ggggcccaga caggaatccg ggacgcgcct gttccagtgt gcagccctgc cccacacttg\n     5761 ctctagtgtc ctctttggct ctctttcacc cccgtgagcc tctctttggg tctttaaaca\n     5821 agggaggaat gcagtagatg attaatgggg aggaaaggcc ctcctgcacg gatccttcct\n     5881 actctctcca gtattcagct ggcaggctac tgagtagcca gcagcacacc ctgaggatgg\n     5941 actgtgtgag cccgagcgag cgctgtcttg tatcccagag cctacctggg gtgcacaggt\n     6001 gaggagtggc tctagcggag ggtaacttca ctttgccaca ctttgttcgt ggttggaacc\n     6061 tggaacacta tctggctagg ctcttctgtc ccaggagctc accactgcgg gcactttgta\n     6121 gtttgttttc ctgatgaggt ccctgggcct ctcacagtag cctgcaggga gggattactg\n     6181 acagcttatt ctagaaaagg aagcccacat tgtcagggaa gttgatttgc ccaaggacac\n     6241 aggagtcagg accgaaacac tgcaggtcac tccattctac cagagtgctt tcctcctctt\n     6301 ctttaaattt ttttccaaat atacaaatta tctattttta gacgacataa atgatgggtt\n     6361 atataatggg ttaggttaca cagataatgt attaacacag tctgtcccca cgatacaaag\n     6421 ttctaactat gggtagagca aaacacccct tgactccagc ttaatcccac tcccctccag\n     6481 ggaagtatgt gctcttctac caatactgca tcctagctcc atatgtctaa atggatggat\n     6541 aaaaatatat ggtctcattt tgttcttata tataagtaac gctctagagt atcacctgca\n     6601 acctgccttt ttcaactaca ccatcaatgc cattttggat caacacgtgg gactcttcgt\n     6661 cgtttgaggc cacacagcag atgctgtctg ccgtgcggag ttgtttctcc tctggtctgg\n     6721 ctgtataccg ggtccgagcg gggcacgtgg ggcccacatc ggaaaatcag cagcctccat\n     6781 ttttctggga ctgtgctaac caggtgaagg gcggccaaag taggttagcg tttatggggc\n     6841 aggtgccctg tggagaaggc ccatcctacc tgggtctctg ctggcttccc agcccccctt\n     6901 caagggactg agaccctctt ctccaggggc acaggccctg caggctgact gacagcatcc\n     6961 tgcttctgct ggttccctga tgcgtgcctt tgacaaggta tttagcttgc tcaaccctga\n     7021 tttccccagt ggtaaagcag ggacggaatg atcagtcaca ctaataaagg gttagtatga\n     7081 ggatgtacgc aaagtacttg gtaaaacttt tttttttttt taagatttta tttatttgac\n     7141 acagagagaa atcacaagta ggcagagagg caggcagaga gagaggggag aaagcaggtt\n     7201 ccctgcagag cagagagccc gacgtggggc tcgatcccag gactctggga tcatgacctg\n     7261 agccgaaggc agaggcttta acccactgag ccacccaggt gccctcttgg taaaactttt\n     7321 ttaaaaaaat atctatttga gagaatgcac acattgggtt tgggggatgg ggaggcagag\n     7381 actctaagta gactctcccc actgagtgtg gagcccaaca caggggcttg atctcacgat\n     7441 cctaagatca ccacctgagc tgaaatcgag tcggccactc aacacttgaa tcacccaggc\n     7501 tcccatggaa acacttttaa aaatgctctc atggtatcat tacttcctct taatggcctc\n     7561 accagctctc tctgcttcca accatcctgg aacagggtga aggaacagga ggtgatggaa\n     7621 agagtaatag aagccccttt cctaatgaag ggaattacag cagaggcact gttttgtccc\n     7681 tttgtggccc atcttccatt tttggaggct cacccgccct gtggggtggg cccattattc\n     7741 cttgttaccg gttcacagct gaggaaacgg agcccccaga atagaggcta cagccatccc\n     7801 caggtcaccc ggcagtcact gaggagttag gatctgaatc caggtcttga gtctcacagt\n     7861 gcagtctctg taggagatgt gggcctgctg cgccctccag aggtcattcc ggtcacagct\n     7921 ggcggcatcc taagagacga gtatctccct gacattaatt cagtcatccg tctgcaacag\n     7981 ttcttacgtg acagacgctg cactgcagat tggtgacatg ccattgcatg gctggatggg\n     8041 ataactctgt tctcggtggc aggtgtgggc aagcacacgg cagcctggga gccaagtcct\n     8101 ccagcctgca ggcacagtct ctacttctta aagtggttgg gaaacaaaag atattttgtg\n     8161 acatgtggaa attatgtgca atttaaattt gtgtccataa ataaagttgg atcgtaacac\n     8221 ggccacgtcc gtttgttgaa gtacctctgt ggctgcactc ccactcccag ccgccgaggg\n     8281 acggccactg gggagctgga agtaacatgc tctctggccc ccgacagcaa gtgggccgac\n     8341 ccctgctgtg cggcaatggc tgtgcagccg ttcattctgc acacactgac caaatgcctc\n     8401 ctacaggagt cttcttccaa gttcacggtt ttgtttctca gatgttctgg tctggacacc\n     8461 ttcgcaatga ttttagagct ccctgctgt\n//\n\nLOCUS       XM_059173983            4872 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 4 (HTR4),\n            transcript variant X2, mRNA.\nACCESSION   XM_059173983\nVERSION     XM_059173983.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081294) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..4872\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="5"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..4872\n                     /gene="HTR4"\n                     /note="5-hydroxytryptamine receptor 4; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 5 Proteins"\n                     /db_xref="GeneID:131831742"\n     CDS             128..1336\n                     /gene="HTR4"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 4 isoform X1"\n                     /protein_id="XP_059029966.1"\n                     /db_xref="GeneID:131831742"\n                     /translation="MDEFDANVSSKEGFGSVEKVVLLTFLSAVILMAILGNLLVMVAV\n                     CRDRQLRKIKTNYFIVSLAFVDLLVSVLVMPFGAIELVQDIWIYGEMFCLVRTSLDVL\n                     LTTASIFHLCCISLDRYYAICCQPLVYRNKMTPLRIALMLGGCWVIPMFISFLPIMQG\n                     WNNIGIIDLERISKPRLGQDLHVIEKRKFNQNSNSTYCIFMVNKPYAITCSVVAFYIP\n                     FLLMVLAYYRIYVTAKEHAHQIQMLQRAGASSEGRPQPADQHSTHRMRTETKAAKTLC\n                     IIMGCFCLCWAPFFVTNIVDPFIDYTVPGQVWTAFLWLGYINSGLNPFLYAFLNKSFR\n                     RAFLIILCCDDERYRRPSILGQTVPCSTTTINGSTHVLRDAVECGGQWESHCHPPATS\n                     SLVAAQPGDP"\n     polyA_site      4872\n                     /gene="HTR4"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 ggcggcagaa gctcggctcg gcggctgggg gtggccgctg caccgtgccg ggcgcctggc\n       61 tccctcgcct cgggcggcgg gaccctgtgg gcactgagat ccaactcaca catgcctatt\n      121 tcctgtaatg gatgaatttg atgctaatgt gagttccaag gagggttttg ggtcagtgga\n      181 gaaggtcgtg ctgctcacgt ttctgtcagc ggttatcctg atggccatct tggggaacct\n      241 gctggtgatg gtggctgtgt gcagggacag gcagctcagg aagataaaaa ccaattattt\n      301 cattgtctct cttgccttcg tggatctgct ggtttcggtg ctggtgatgc cctttggtgc\n      361 cattgagctg gttcaagaca tctggatcta tggggagatg ttttgcctcg ttcggacatc\n      421 tctagacgtc ctgctcacga cggcatcaat ttttcacctg tgctgcattt ctctggatcg\n      481 gtattatgcc atctgctgcc agcctctggt ctataggaac aagatgaccc ctctgcgcat\n      541 cgcattaatg ctgggaggct gctgggtcat ccctatgttt atctcttttc tccctataat\n      601 gcaaggctgg aataatattg gcatcattga tctggagagg atatccaagc caaggctggg\n      661 ccaggatttg catgtgatag aaaaaaggaa gttcaaccag aactctaact ctacgtactg\n      721 tatcttcatg gtcaacaagc cctacgccat cacctgctcc gtggtggcct tctacatccc\n      781 gtttctcctc atggtgctgg cctattaccg catctacgtc acagcgaagg agcacgccca\n      841 tcagatccag atgttacaac gggccggggc ctcctcagaa ggcaggcccc agccagctga\n      901 ccagcacagc actcatcgca tgaggacaga gaccaaagca gccaagaccc tgtgcatcat\n      961 catgggctgc ttctgcctct gctgggcacc attctttgtc accaatatcg tggatccttt\n     1021 catagactac accgttcctg ggcaggtgtg gaccgctttc ctctggcttg gctacatcaa\n     1081 ctctgggttg aacccctttc tctacgcctt cttgaataag tcttttagac gtgccttcct\n     1141 catcatcctc tgctgtgacg atgagcgcta ccgaagaccc tccatcttgg gccagactgt\n     1201 cccctgttca accacaacca ttaatggatc cacacacgtg ctaagggatg cggtggagtg\n     1261 tggtggccaa tgggagagtc actgccatcc tccagcaact tcttctttgg tggctgctca\n     1321 gcctggtgac ccttagtccc tggggcggtg actcagaaga cagccatccc tcggagagag\n     1381 ggcagattct aaactgctgc ttgtgtggga ccgctcctgc cattctctcc agcacgcctt\n     1441 ccgccaggca gccgcgccca ccgggatttt ctctggggct ccagcaggtg gcgctggagg\n     1501 gacccagggg actggaggcc tcctccttcc ctggggtttc tcttccagag atcctctacg\n     1561 aagggatttt tttttttttt ttttcttttt ccagcactcc ctcttcctgg cgtctcgccc\n     1621 ttgcgtcaca ctctctgttg tccccaatat gtccccttac tgttcctggt ttgtctctca\n     1681 tgttccaaac accatcgctc actgtgtcct atctcagtca tagatgtctt caaatatgcc\n     1741 ttctttgctg tgtctgcaca cagacattgt caaaacacat cctcctggtg cctgtcttgg\n     1801 tcagagccat gttccaaaag cacacatttc ttgctcattc acgcctgtta caaccatgtt\n     1861 caaactcctc gttgtcttat ctctgtcctg ttctgggcca gatcctgttc tgggccagac\n     1921 gctaatacac tttcttcctg gtgtttgggt ccaaacctgc atcctcttgg ccagcccccg\n     1981 tgtcagttgt agatctcctg cccactcttc cttgaggcca gttccagtcc tcttcaggat\n     2041 atgctccatt tacttaccgt ggaagaaatg ggagcagaga tctatctgaa aacagtgtct\n     2101 gcggcagcct tggagtttgg ccagagacag cttcccccag tgccgtggcc tcgggccctg\n     2161 ctgctccgag atgcttgctt ccttcttgga ctagaaccgg catcttctgc tgaagggcct\n     2221 aaggcagggc caacaacatt gtagtgtttt ttaaagactt tggaatcttt cccttgaact\n     2281 tgtggcaaaa cccacagtag cagcttaaaa gccttgaatc tggccttgtt gttcccaaag\n     2341 gaaagaactc ttggcagctc acactgggga taagtgaacc tcctcactgc acgtggagga\n     2401 gggccagact aagccgtgtc tgggggggaa cagagtgctt gacttgaagt caaggacccc\n     2461 gattccagcc ctggctctgc tcctaacatg ctgtgagctc ttggcccatg ctcttccatt\n     2521 cctggacctc actttctaca tctgtgaact gaagttcaga ctcccagatc tccaagatcc\n     2581 ctttctggtt ctaggaccaa ggatactgct acatccctca gctacctcga aaagcccgtg\n     2641 gcttgcctgc cttttgactt tgtttcaaag gaatcaccct cctcatttgg gccttctaga\n     2701 ctcttgatct tgccaacttt gtccttcgaa ttaaccagga agtcttttag tcgaagctga\n     2761 ggtccttggc tcttaccaac tgccccagag taaaagtccc agggaactag acaccgccat\n     2821 gtcctagagc catgtaaggt tctaacagtg atcctggctg ggatttgatc gcatctcagg\n     2881 actttatcat actcattgtt cctgctgctt aaaagatgtc agttaccatt tccactgatg\n     2941 ttgactttgg ttctggaatt gaaccggaaa ggaaagagac tgaaataagg aagaaaagat\n     3001 tgtcctcaaa ccatctaaat gccagaacaa aacaaaacaa aaccccacaa aacccaaaaa\n     3061 caaaacaaaa caaaataaca aaacccaaaa caaaacaaaa aaaccctctg tcctgcaaaa\n     3121 gcttaatttt gttggggaga aagtcacacc ttagggaagg gaaaaagcct ctaaagacaa\n     3181 atgttattta gtactcctga atgcagttga gacttacggc aacgtgctga aacgttccct\n     3241 gtctaggctg gaaccctcac tgatcagatt gaagatctga ttgaactgga gatctagcct\n     3301 catccaggac aaagagagtt tacgtgagtc ctaatgggca ccttgactct ggctggacca\n     3361 atttcttttg ctttttcaag tccctgtttg ctgactgcat tcaggcttag gcgactgcca\n     3421 tcatcttgag gatggttctt tcttaataca agggaggcag caacaaggtt ctgaggccca\n     3481 aggtcctgaa gtcagcaatg ggccccaaac tctctgctcg gcttgacatg ctacccgttg\n     3541 cctctgtgag cgcgagggag agatggctgt ggtagagaag cgccatgctg actctcgctg\n     3601 tgtgaccttc aacctctctg gccttgaaag aatccctctt ggctacttcg caaagttgtt\n     3661 gtggagataa aaaagataat ttttgtgaaa acatcctgta aatcataaaa tgctattttg\n     3721 tatgtttatc cttactttgg attactttgg atgctcctga atgcccaagg acaaagaatt\n     3781 tcctcaccaa gatgtgaacc agtttagaga atgagcttcc catgttgaaa aaccatacca\n     3841 agggagcacc tttcagggtt tctttcttcc aaatccaccc ctcctcgttt ggttaccgca\n     3901 cacacccaca ctgcaaattt atacagcaga aacattctca tttgaaggga tattgttatt\n     3961 cttaaaggag tcggtggagg gagatggtga ccacaggcta atttggtaat aatgagcctt\n     4021 gatttcatga aacgtcaaag tcacatgaca aaaattcaca tgcccgtttg tcgtgcaaac\n     4081 atttattttg agaataaaga cctgggtcat cgaaatgatc cccactttgt aactgttata\n     4141 aatatatata tatatatata tatatatata tatatacata taaattctgt gcaaataaaa\n     4201 aactcaaaca tggattattt atgaacgagc agctgacaag actgttacag gaagaatcta\n     4261 ctgagctact gaaccagata attctaaaaa atgttttcta atctgatagc catgtaaact\n     4321 attgttaatt atggtttaat attatttagg caccacctaa attttgttta cattttcaat\n     4381 aaagtagaat tagagtgggg ccactcctac agtttataat gcactaagtg tcctgtataa\n     4441 tcaacatgta atgtacatat gtgcctgtta tagagaatat ggaatttaat tatataattt\n     4501 taaaggattg caaattttag tgatggttgt atctttggtt ttatgagatt attagttaca\n     4561 tctgtgattt attggaggct aaagctttga aggtactggg gtccctcaat ctaatttgtc\n     4621 tctctggaaa acactcttga gtttacctgc tcttgatact gttcccagga atgcattctg\n     4681 ggaaaaacag gaactaacat agtctttctt ttgtaataga taaattctat ttattgataa\n     4741 atatttgata aattccacat ctgtttatat ttatgcattc tgtacatgtt tatataaatt\n     4801 acatatttag ggaaatctta agtctcaaaa ttaataactg aattttgaaa cacaataaaa\n     4861 tgccaaagtc aa\n//\n\nLOCUS       XM_059173982            4919 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 4 (HTR4),\n            transcript variant X1, mRNA.\nACCESSION   XM_059173982\nVERSION     XM_059173982.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081294) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..4919\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="5"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..4919\n                     /gene="HTR4"\n                     /note="5-hydroxytryptamine receptor 4; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 5 Proteins"\n                     /db_xref="GeneID:131831742"\n     CDS             175..1383\n                     /gene="HTR4"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 4 isoform X1"\n                     /protein_id="XP_059029965.1"\n                     /db_xref="GeneID:131831742"\n                     /translation="MDEFDANVSSKEGFGSVEKVVLLTFLSAVILMAILGNLLVMVAV\n                     CRDRQLRKIKTNYFIVSLAFVDLLVSVLVMPFGAIELVQDIWIYGEMFCLVRTSLDVL\n                     LTTASIFHLCCISLDRYYAICCQPLVYRNKMTPLRIALMLGGCWVIPMFISFLPIMQG\n                     WNNIGIIDLERISKPRLGQDLHVIEKRKFNQNSNSTYCIFMVNKPYAITCSVVAFYIP\n                     FLLMVLAYYRIYVTAKEHAHQIQMLQRAGASSEGRPQPADQHSTHRMRTETKAAKTLC\n                     IIMGCFCLCWAPFFVTNIVDPFIDYTVPGQVWTAFLWLGYINSGLNPFLYAFLNKSFR\n                     RAFLIILCCDDERYRRPSILGQTVPCSTTTINGSTHVLRDAVECGGQWESHCHPPATS\n                     SLVAAQPGDP"\n     polyA_site      4919\n                     /gene="HTR4"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 cccgcagccg tcgcggtcgc ctctcccagg gcggggggcg gggtggggac cgccggggct\n       61 gggggcgtgg aacccgcgca gccctgcccc gctggccggg gagaaggacg atgcgcggcg\n      121 cgcccaggac cctgtgggca ctgagatcca actcacacat gcctatttcc tgtaatggat\n      181 gaatttgatg ctaatgtgag ttccaaggag ggttttgggt cagtggagaa ggtcgtgctg\n      241 ctcacgtttc tgtcagcggt tatcctgatg gccatcttgg ggaacctgct ggtgatggtg\n      301 gctgtgtgca gggacaggca gctcaggaag ataaaaacca attatttcat tgtctctctt\n      361 gccttcgtgg atctgctggt ttcggtgctg gtgatgccct ttggtgccat tgagctggtt\n      421 caagacatct ggatctatgg ggagatgttt tgcctcgttc ggacatctct agacgtcctg\n      481 ctcacgacgg catcaatttt tcacctgtgc tgcatttctc tggatcggta ttatgccatc\n      541 tgctgccagc ctctggtcta taggaacaag atgacccctc tgcgcatcgc attaatgctg\n      601 ggaggctgct gggtcatccc tatgtttatc tcttttctcc ctataatgca aggctggaat\n      661 aatattggca tcattgatct ggagaggata tccaagccaa ggctgggcca ggatttgcat\n      721 gtgatagaaa aaaggaagtt caaccagaac tctaactcta cgtactgtat cttcatggtc\n      781 aacaagccct acgccatcac ctgctccgtg gtggccttct acatcccgtt tctcctcatg\n      841 gtgctggcct attaccgcat ctacgtcaca gcgaaggagc acgcccatca gatccagatg\n      901 ttacaacggg ccggggcctc ctcagaaggc aggccccagc cagctgacca gcacagcact\n      961 catcgcatga ggacagagac caaagcagcc aagaccctgt gcatcatcat gggctgcttc\n     1021 tgcctctgct gggcaccatt ctttgtcacc aatatcgtgg atcctttcat agactacacc\n     1081 gttcctgggc aggtgtggac cgctttcctc tggcttggct acatcaactc tgggttgaac\n     1141 ccctttctct acgccttctt gaataagtct tttagacgtg ccttcctcat catcctctgc\n     1201 tgtgacgatg agcgctaccg aagaccctcc atcttgggcc agactgtccc ctgttcaacc\n     1261 acaaccatta atggatccac acacgtgcta agggatgcgg tggagtgtgg tggccaatgg\n     1321 gagagtcact gccatcctcc agcaacttct tctttggtgg ctgctcagcc tggtgaccct\n     1381 tagtccctgg ggcggtgact cagaagacag ccatccctcg gagagagggc agattctaaa\n     1441 ctgctgcttg tgtgggaccg ctcctgccat tctctccagc acgccttccg ccaggcagcc\n     1501 gcgcccaccg ggattttctc tggggctcca gcaggtggcg ctggagggac ccaggggact\n     1561 ggaggcctcc tccttccctg gggtttctct tccagagatc ctctacgaag ggattttttt\n     1621 tttttttttt tctttttcca gcactccctc ttcctggcgt ctcgcccttg cgtcacactc\n     1681 tctgttgtcc ccaatatgtc cccttactgt tcctggtttg tctctcatgt tccaaacacc\n     1741 atcgctcact gtgtcctatc tcagtcatag atgtcttcaa atatgccttc tttgctgtgt\n     1801 ctgcacacag acattgtcaa aacacatcct cctggtgcct gtcttggtca gagccatgtt\n     1861 ccaaaagcac acatttcttg ctcattcacg cctgttacaa ccatgttcaa actcctcgtt\n     1921 gtcttatctc tgtcctgttc tgggccagat cctgttctgg gccagacgct aatacacttt\n     1981 cttcctggtg tttgggtcca aacctgcatc ctcttggcca gcccccgtgt cagttgtaga\n     2041 tctcctgccc actcttcctt gaggccagtt ccagtcctct tcaggatatg ctccatttac\n     2101 ttaccgtgga agaaatggga gcagagatct atctgaaaac agtgtctgcg gcagccttgg\n     2161 agtttggcca gagacagctt cccccagtgc cgtggcctcg ggccctgctg ctccgagatg\n     2221 cttgcttcct tcttggacta gaaccggcat cttctgctga agggcctaag gcagggccaa\n     2281 caacattgta gtgtttttta aagactttgg aatctttccc ttgaacttgt ggcaaaaccc\n     2341 acagtagcag cttaaaagcc ttgaatctgg ccttgttgtt cccaaaggaa agaactcttg\n     2401 gcagctcaca ctggggataa gtgaacctcc tcactgcacg tggaggaggg ccagactaag\n     2461 ccgtgtctgg gggggaacag agtgcttgac ttgaagtcaa ggaccccgat tccagccctg\n     2521 gctctgctcc taacatgctg tgagctcttg gcccatgctc ttccattcct ggacctcact\n     2581 ttctacatct gtgaactgaa gttcagactc ccagatctcc aagatccctt tctggttcta\n     2641 ggaccaagga tactgctaca tccctcagct acctcgaaaa gcccgtggct tgcctgcctt\n     2701 ttgactttgt ttcaaaggaa tcaccctcct catttgggcc ttctagactc ttgatcttgc\n     2761 caactttgtc cttcgaatta accaggaagt cttttagtcg aagctgaggt ccttggctct\n     2821 taccaactgc cccagagtaa aagtcccagg gaactagaca ccgccatgtc ctagagccat\n     2881 gtaaggttct aacagtgatc ctggctggga tttgatcgca tctcaggact ttatcatact\n     2941 cattgttcct gctgcttaaa agatgtcagt taccatttcc actgatgttg actttggttc\n     3001 tggaattgaa ccggaaagga aagagactga aataaggaag aaaagattgt cctcaaacca\n     3061 tctaaatgcc agaacaaaac aaaacaaaac cccacaaaac ccaaaaacaa aacaaaacaa\n     3121 aataacaaaa cccaaaacaa aacaaaaaaa ccctctgtcc tgcaaaagct taattttgtt\n     3181 ggggagaaag tcacacctta gggaagggaa aaagcctcta aagacaaatg ttatttagta\n     3241 ctcctgaatg cagttgagac ttacggcaac gtgctgaaac gttccctgtc taggctggaa\n     3301 ccctcactga tcagattgaa gatctgattg aactggagat ctagcctcat ccaggacaaa\n     3361 gagagtttac gtgagtccta atgggcacct tgactctggc tggaccaatt tcttttgctt\n     3421 tttcaagtcc ctgtttgctg actgcattca ggcttaggcg actgccatca tcttgaggat\n     3481 ggttctttct taatacaagg gaggcagcaa caaggttctg aggcccaagg tcctgaagtc\n     3541 agcaatgggc cccaaactct ctgctcggct tgacatgcta cccgttgcct ctgtgagcgc\n     3601 gagggagaga tggctgtggt agagaagcgc catgctgact ctcgctgtgt gaccttcaac\n     3661 ctctctggcc ttgaaagaat ccctcttggc tacttcgcaa agttgttgtg gagataaaaa\n     3721 agataatttt tgtgaaaaca tcctgtaaat cataaaatgc tattttgtat gtttatcctt\n     3781 actttggatt actttggatg ctcctgaatg cccaaggaca aagaatttcc tcaccaagat\n     3841 gtgaaccagt ttagagaatg agcttcccat gttgaaaaac cataccaagg gagcaccttt\n     3901 cagggtttct ttcttccaaa tccacccctc ctcgtttggt taccgcacac acccacactg\n     3961 caaatttata cagcagaaac attctcattt gaagggatat tgttattctt aaaggagtcg\n     4021 gtggagggag atggtgacca caggctaatt tggtaataat gagccttgat ttcatgaaac\n     4081 gtcaaagtca catgacaaaa attcacatgc ccgtttgtcg tgcaaacatt tattttgaga\n     4141 ataaagacct gggtcatcga aatgatcccc actttgtaac tgttataaat atatatatat\n     4201 atatatatat atatatatat atacatataa attctgtgca aataaaaaac tcaaacatgg\n     4261 attatttatg aacgagcagc tgacaagact gttacaggaa gaatctactg agctactgaa\n     4321 ccagataatt ctaaaaaatg ttttctaatc tgatagccat gtaaactatt gttaattatg\n     4381 gtttaatatt atttaggcac cacctaaatt ttgtttacat tttcaataaa gtagaattag\n     4441 agtggggcca ctcctacagt ttataatgca ctaagtgtcc tgtataatca acatgtaatg\n     4501 tacatatgtg cctgttatag agaatatgga atttaattat ataattttaa aggattgcaa\n     4561 attttagtga tggttgtatc tttggtttta tgagattatt agttacatct gtgatttatt\n     4621 ggaggctaaa gctttgaagg tactggggtc cctcaatcta atttgtctct ctggaaaaca\n     4681 ctcttgagtt tacctgctct tgatactgtt cccaggaatg cattctggga aaaacaggaa\n     4741 ctaacatagt ctttcttttg taatagataa attctattta ttgataaata tttgataaat\n     4801 tccacatctg tttatattta tgcattctgt acatgtttat ataaattaca tatttaggga\n     4861 aatcttaagt ctcaaaatta ataactgaat tttgaaacac aataaaatgc caaagtcaa\n//\n\nLOCUS       XM_059172349            2610 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 5A\n            (HTR5A), mRNA.\nACCESSION   XM_059172349\nVERSION     XM_059172349.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081293) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..2610\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="4"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..2610\n                     /gene="HTR5A"\n                     /note="5-hydroxytryptamine receptor 5A; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 9 Proteins"\n                     /db_xref="GeneID:131829979"\n     CDS             737..1813\n                     /gene="HTR5A"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 5A"\n                     /protein_id="XP_059028332.1"\n                     /db_xref="GeneID:131829979"\n                     /translation="MDSPVNLTYFFLSTPAPSETNHSSLDAEDPRPSPPLHSVFGVLV\n                     LTLLGFLVAATFSWNLLVLATILRVRTFHRVPHNLVASMAISDVLVAALVMPLSLVHE\n                     LSGRRWQLGRRLCQLWIACDVLCCTASIWNVTAIALDRYWSVARHLEYTPRARKRISN\n                     VMIVLTWALSAVISLAPLLFGWGETYSERSEECQVSREPSYTVFSTVGAFYLPLCVVL\n                     FVYWKVYKAAKLRVGSRKTNSVSPWPEAVEAKTPAPQPQMVFTVRHTTVTFQTEGDTW\n                     REQKEQRAALMVGILIGVFALCWLPFFTTELIGPLCAYDIPAVWKSIFLWLGYSNSFF\n                     NPLIYTAFNKNYNSAFKNFFCRQH"\nORIGIN      \n        1 agcgcatttc gggaagcagg gccagtaccg cggacagcac caggaccccg gcccagggtg\n       61 ggggagacag cagcaccacg gacagcacca ccgggagcga gcactgcgcg ctctgggcgg\n      121 aggggcgggg ataggcggcc tcatcagctg atgcctgacg taggctggat ccccactttg\n      181 agaagcaggt ctggaggggc gcgccggcgt tccgccccag agccgcggcc ccagacggcg\n      241 tggggctggg gctggggcga tagcaggagg cagatcccca gaaaaacggc ccctgcctgg\n      301 cttccctgca cgggcttgag gctgcagccc gccgcccgga ggggcgagga gggagcggac\n      361 gcgcagcgca agtcctgctc tgacgcacca gcacccctcc ggcacccaca ggctccggag\n      421 gcgccagctg ccccccgact cgggagatgc tcagctctgg gtgaccagac tgctgtccgt\n      481 gccgcgggga aaagccccgg caagtgacgg cttcggaggg ccccggctgc gctgcgagac\n      541 gcagcccagc agcctcgtct cagccacccc gtctcccgcg tgtgctcgct ggcaggaggt\n      601 ttcggaaaca atccccagaa accccgccac cagccagagg tcgcaaacac cccgagtggc\n      661 tccgggcgca ggggccacga ctgtcttccc gaacgcccct tctgcacgca ccccgggccg\n      721 gtctcctgac ccagcgatgg attcacctgt gaacctaacc tatttttttc tctccacccc\n      781 cgccccttcg gagaccaacc acagcagcct tgacgccgaa gacccgcgcc ccagcccgcc\n      841 cctccactct gtcttcggtg tgcttgttct gaccttgctg ggctttctgg tggctgcgac\n      901 gttctcctgg aacctcctgg tactggcgac catcctccgt gtgcgcacct tccaccgggt\n      961 tccgcacaac ttagtggcgt ccatggccat ctcggacgtg ctcgtggcgg ctctggtcat\n     1021 gccgctgagc ctggtgcatg agttgtccgg ccggcgctgg cagctgggtc ggcggctgtg\n     1081 ccagctgtgg atcgcgtgcg acgtgctctg ctgcaccgcc agcatctgga atgtgaccgc\n     1141 catcgcgctg gaccgctatt ggtccgtcgc gcgtcacctg gaatacacgc cccgcgcccg\n     1201 caagcgcatc tccaatgtga tgatcgtgct cacctgggca ctctccgcgg tgatctcgct\n     1261 ggcgccgctg ctcttcggct ggggggagac atactcggag cgcagcgagg agtgccaggt\n     1321 gagccgcgag ccctcctaca ccgtgttctc caccgtgggc gccttctacc tgccgctctg\n     1381 cgtggtgctc ttcgtgtact ggaaggtcta caaggccgcc aagctccgcg tgggctccag\n     1441 gaagaccaac agcgtgtcac cctggccgga ggctgtggag gcgaagaccc ctgcgccgca\n     1501 gccccagatg gtgttcaccg tgcgccacac cactgtcacc ttccagacag aaggggacac\n     1561 gtggagggaa cagaaggagc agagagctgc cctgatggtg ggcatcctca tcggggtgtt\n     1621 cgcgctctgc tggctgccct tcttcaccac ggagctcatc ggccctctct gcgcctacga\n     1681 catccctgcc gtctggaaga gcatcttcct ttggctcggc tactccaact ccttcttcaa\n     1741 cccgctcatc tacacagcgt tcaacaagaa ctataacagc gccttcaaga acttcttttg\n     1801 taggcaacac tgagcgggag gcctggggag gagggacaag atcctcgaac tcagtgagat\n     1861 ttccagctcc atctgcttcc ccgtccctac catggacccc ttccacatgg aagaggcatg\n     1921 tcctccaggc tctccggggt catcttcaga actagccctc acttccccac tccgaggtag\n     1981 gaatgtgggt cttcacaggc agcttgggtg cccttttttt ttcttttaca attttttttt\n     2041 aaaagatttt atttatctga cagagagatc acaagtgggc agagaggcag gcagagagag\n     2101 aggaggaagc aggctcccca ctgagcagag agcccgatgc cggggctcca tcccaggacc\n     2161 ctgagatcat gacctgagcc accaagatgc ccctgggtga ccttcttgat ctaacttaat\n     2221 ctgttattgt tcactctgca cctaacagcc acagactttg cccacaaaat gccctccccc\n     2281 tccccccagt ccactccagc ctggccgtcg tcctggcccc agagcagtca tacaaggtaa\n     2341 acgagaggaa ggaaatcaag caacgtggct agaaaatgat ggagaagaag tcagaacggg\n     2401 gacaccagag gggcaggaaa ccagaattcc cagttttctg gtagagtccc taacttgaaa\n     2461 tttcgttcta tggtcctggt aagtataccc tagtacttac tgtgtacgtc ccagtgtttg\n     2521 gctacaagat attgtctcta accctattga agtgcatagc cacagcacag cagctgtgaa\n     2581 tattggcttt aagactttgt ggcaaccaca\n//\n\nLOCUS       XM_059169491            1713 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 7 (HTR7),\n            transcript variant X3, mRNA.\nACCESSION   XM_059169491\nVERSION     XM_059169491.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081293) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..1713\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="4"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..1713\n                     /gene="HTR7"\n                     /note="5-hydroxytryptamine receptor 7; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon."\n                     /db_xref="GeneID:131828667"\n     CDS             364..1557\n                     /gene="HTR7"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 7 isoform X3"\n                     /protein_id="XP_059025474.1"\n                     /db_xref="GeneID:131828667"\n                     /translation="MMDVNSSGRPDLYGHLRSLLLPEVGRGLPDLSPDGAGPVSGSWA\n                     PHLLRGVPEVTASPVPTWDAPPDNASGCGEQINYGRAEKVVIGSILTLITLLTIAGNC\n                     LVVISVCFVKKLRQPSNYLIVSLALADLSVAVAVMPFVSVTDLIGGKWIFGHFFCNVF\n                     IAMDVMCCTASIMTLCVISIDRIVPLFCDPSQERRDEVPRDHAAAHVPREAERQVHGE\n                     NDSVCLAAFSLHHLTPALRLGSERERRQGVPDQPGLWLHHLLHGSGVLHPHVRHAVHV\n                     LPDLQGCAEERRQAQVPRFPPARGARQQHLPERHGEAPEGGGGVCQPFETPQTREEKH\n                     LHLQAGAESGHHLGHHRGGLHRVLAAVLPSLHRQTLHLRHGLQLHPAVGGEDLSVAGL\n                     RQLSH"\n     polyA_site      1713\n                     /gene="HTR7"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 tccgcaactt ctgccgctgc ctgccgggcg cgctcggccg aggcgcgcgg cggctgcggg\n       61 ctgcggggcg gccagccgag cggcgcccgc gggcccgtga gccgcgcgtc gcgggcgtcc\n      121 gtctgtgtcg ggggcgcctc ccgcggggag tctcggcgcg gtcgtgctcc cgcgtggtcc\n      181 gcagcggctg gggccccggg acgtgcgggg ccgcggggcc gagccgaggc gccccccagc\n      241 ggccggcgcg ggtcccatgg ctgggccggg cggagcggaa ccggcgaggt gaagcccccg\n      301 ggccggaggc cggagcgcgt ggcgggggcg ccggctccat gggcagcagc gcacagcggc\n      361 acgatgatgg acgttaacag cagcggccgc ccggacctct acgggcacct ccgctctttg\n      421 ctcctgccgg aggtggggcg cgggctgccg gacctgagcc ccgacggcgc cggcccggtc\n      481 tcgggctcct gggcgccgca cctgctgcgc ggggtcccag aggtgacggc cagcccggtg\n      541 cccacctggg acgcgccgcc ggacaatgcc tccggctgcg gggagcagat caactatggc\n      601 agagccgaga aagttgtgat cggctccatc ctgacgctca tcacgctgct gacgatcgca\n      661 ggcaactgcc tggtggtgat ctcggtgtgc ttcgtcaaga agctccgcca gccctccaac\n      721 tacctgatcg tgtccctggc gctggccgac ctctcggtgg ccgtggcggt catgcccttc\n      781 gtcagcgtca ccgacctcat cgggggcaag tggatctttg gccacttctt ctgcaacgtc\n      841 ttcatcgcca tggacgtcat gtgctgcacg gcctcgatca tgaccttatg cgtgatcagc\n      901 atcgacagaa ttgtgcccct tttttgtgat ccttctcagg agaggagaga tgaggtacct\n      961 cgggatcacg cggccgctca cgtaccccgt gaggcagaac ggcaagtgca tggcgaaaat\n     1021 gattctgtct gtctggctgc tttcagcctc catcacctta cccccgctct tcggttgggc\n     1081 tcagaacgtg aacgacgaca aggtgtgcct gatcagccag gactttggct acaccatcta\n     1141 ctccacggca gtggcgtttt acatccccat gtccgtcatg ctgttcatgt actaccagat\n     1201 ctacaaggct gcgcggaaga gcgccgccaa gcacaagttc cccggtttcc cccggcccga\n     1261 ggagccagac agcagcatct ccctgaacgg catggtgaag ctccagaagg aggtggagga\n     1321 gtgtgccaac ctttcgagac tcctcaaaca cgagaggaaa aacatctcca tcttcaagcg\n     1381 ggagcagaaa gcggccacca ccttgggcat catcgtgggg gccttcaccg tgtgctggct\n     1441 gccgttcttc cttctctcca ccgccagacc cttcatctgc ggcacggcct gcagctgcat\n     1501 cccgctgtgg gtggagagga cctttctgtg gctgggctac gccaactctc tcattaaccc\n     1561 ttttatatat gccttcttca accgggatct gaggaccacc taccgcagcc tgctccagtg\n     1621 ccagtaccgg aacatcaacc gcaagctgtc ggctgcaggc atgcacgaag ccctgaagct\n     1681 cgccgagagg cccgagagac ctgagtttgt gct\n//\n\nLOCUS       XM_059169490            3403 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 7 (HTR7),\n            transcript variant X2, mRNA.\nACCESSION   XM_059169490\nVERSION     XM_059169490.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081293) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..3403\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="4"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..3403\n                     /gene="HTR7"\n                     /note="5-hydroxytryptamine receptor 7; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 9 Proteins"\n                     /db_xref="GeneID:131828667"\n     CDS             356..1663\n                     /gene="HTR7"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 7 isoform X2"\n                     /protein_id="XP_059025473.1"\n                     /db_xref="GeneID:131828667"\n                     /translation="MMDVNSSGRPDLYGHLRSLLLPEVGRGLPDLSPDGAGPVSGSWA\n                     PHLLRGVPEVTASPVPTWDAPPDNASGCGEQINYGRAEKVVIGSILTLITLLTIAGNC\n                     LVVISVCFVKKLRQPSNYLIVSLALADLSVAVAVMPFVSVTDLIGGKWIFGHFFCNVF\n                     IAMDVMCCTASIMTLCVISIDRYLGITRPLTYPVRQNGKCMAKMILSVWLLSASITLP\n                     PLFGWAQNVNDDKVCLISQDFGYTIYSTAVAFYIPMSVMLFMYYQIYKAARKSAAKHK\n                     FPGFPRPEEPDSSISLNGMVKLQKEVEECANLSRLLKHERKNISIFKREQKAATTLGI\n                     IVGAFTVCWLPFFLLSTARPFICGTACSCIPLWVERTFLWLGYANSLINPFIYAFFNR\n                     DLRTTYRSLLQCQYRNINRKLSAAGMHEALKLAERPERPEFVL"\n     polyA_site      3403\n                     /gene="HTR7"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 ttctgccgct gcctgccggg cgcgctcggc cgaggcgcgc ggcggctgcg ggctgcgggg\n       61 cggccagccg agcggcgccc gcgggcccgt gagccgcgcg tcgcgggcgt ccgtctgtgt\n      121 cgggggcgcc tcccgcgggg agtctcggcg cggtcgtgct cccgcgtggt ccgcagcggc\n      181 tggggccccg ggacgtgcgg ggccgcgggg ccgagccgag gcgcccccca gcggccggcg\n      241 cgggtcccat ggctgggccg ggcggagcgg aaccggcgag gtgaagcccc cgggccggag\n      301 gccggagcgc gtggcggggg cgccggctcc atgggcagca gcgcacagcg gcacgatgat\n      361 ggacgttaac agcagcggcc gcccggacct ctacgggcac ctccgctctt tgctcctgcc\n      421 ggaggtgggg cgcgggctgc cggacctgag ccccgacggc gccggcccgg tctcgggctc\n      481 ctgggcgccg cacctgctgc gcggggtccc agaggtgacg gccagcccgg tgcccacctg\n      541 ggacgcgccg ccggacaatg cctccggctg cggggagcag atcaactatg gcagagccga\n      601 gaaagttgtg atcggctcca tcctgacgct catcacgctg ctgacgatcg caggcaactg\n      661 cctggtggtg atctcggtgt gcttcgtcaa gaagctccgc cagccctcca actacctgat\n      721 cgtgtccctg gcgctggccg acctctcggt ggccgtggcg gtcatgccct tcgtcagcgt\n      781 caccgacctc atcgggggca agtggatctt tggccacttc ttctgcaacg tcttcatcgc\n      841 catggacgtc atgtgctgca cggcctcgat catgacctta tgcgtgatca gcatcgacag\n      901 gtacctcggg atcacgcggc cgctcacgta ccccgtgagg cagaacggca agtgcatggc\n      961 gaaaatgatt ctgtctgtct ggctgctttc agcctccatc accttacccc cgctcttcgg\n     1021 ttgggctcag aacgtgaacg acgacaaggt gtgcctgatc agccaggact ttggctacac\n     1081 catctactcc acggcagtgg cgttttacat ccccatgtcc gtcatgctgt tcatgtacta\n     1141 ccagatctac aaggctgcgc ggaagagcgc cgccaagcac aagttccccg gtttcccccg\n     1201 gcccgaggag ccagacagca gcatctccct gaacggcatg gtgaagctcc agaaggaggt\n     1261 ggaggagtgt gccaaccttt cgagactcct caaacacgag aggaaaaaca tctccatctt\n     1321 caagcgggag cagaaagcgg ccaccacctt gggcatcatc gtgggggcct tcaccgtgtg\n     1381 ctggctgccg ttcttccttc tctccaccgc cagacccttc atctgcggca cggcctgcag\n     1441 ctgcatcccg ctgtgggtgg agaggacctt tctgtggctg ggctacgcca actctctcat\n     1501 taaccctttt atatatgcct tcttcaaccg ggatctgagg accacctacc gcagcctgct\n     1561 ccagtgccag taccggaaca tcaaccgcaa gctgtcggct gcaggcatgc acgaagccct\n     1621 gaagctcgcc gagaggcccg agagacctga gtttgtgctg taagacaaaa ctctgactac\n     1681 tgtaggaaaa aaagtcatga ttcatgatca aacgtggaat aatgaaaacg aaatcaacaa\n     1741 ggcaagacag aggtggaaac agaactcaac catttgctga ggccgcggaa tggagcgcgg\n     1801 cttgtccttt cctggggtgg ctgagacgtg acaagcagag tgatctgttg tacaaagcat\n     1861 gttgtgagag agatggtgac ctcttgtctt tttctgtgga tcagtgctgt tgtgtgccaa\n     1921 agaaaatagt tttccgttta agacggccag atcagctcag cggtaagcac acaaacagaa\n     1981 ctgagtccca gaaaagaagc cgtttctggt gctttgtgta cgtccaagcc cctacaaatg\n     2041 gaagaaagtt ccaatgcgca cttcccatgc ttccaagtct aggcattgtg gtgaatattc\n     2101 aggaatcatt tacgagacag aatgtatttt gtggcaggac agaagggtgt gtttttccaa\n     2161 gcaaactgtg gtaagcgtag cgttgaatgt gttgcatgtc cgtgttagaa aacagaatcc\n     2221 cgtcatcagc taatacaaat gatgtcccag agcagtgtct ggttcaagct tctgtcaaat\n     2281 agttttgctt ttttgcaggg tccctgtgac ttccccaccg atgtactttt ctttgtgaac\n     2341 tcttgtattg ttatggtatc actcaggaac agatctcagg atggagagaa tcatcaaacc\n     2401 taaataaagc tttttcttgt actcacactt cttctgaagg gtcctgagag gggaggaggg\n     2461 ttcctttggt aggctttgta cctacctgga tgaagagcag gggccactga actgtgctgt\n     2521 ctaccagcat ggctgtgggc ataaaacttc aggtgtagat atcaggttga cacaactgtg\n     2581 gtgggctccc aggccggaca ataaccatgt gttttggggg aggaagtatg ggaataagaa\n     2641 aggtttccat gggaagttat gatgctttca gacatggagc atcaacattg ttaattcttg\n     2701 ggcagcattg tattaaaggg aaccatgtga cttggaggtc acctgggctg ctactgggaa\n     2761 acactcagaa cactattctc ttcctttagg aggatttgtt ttcatgttct ctgtaaccta\n     2821 aatcaaatgt gtgcctggcc agttctgttc ttcttccctc tccctcctca aagtggtaga\n     2881 catgaaggca ggtaaaccag aaaaggccct gatgcaaata gtttgttggg tttttttgtt\n     2941 ttgtttttgt ttttaatgta caagtaatat gtaataagac aggaagatgg tggatcggaa\n     3001 gagtacctcc aaggggagaa agtgaacaca aagttttgtt tgataaaaga gaactgacag\n     3061 agaaaattat tttcctacaa gaaaggtagc tgttctcttc cagaagacta tggaattcca\n     3121 acgtggattt tggatatctt ctgctttcac tgaacattgc atctcaccag acacaaggaa\n     3181 gggtctagag gggaggtggg tgctgtcctc tcagacaaag cttgtacaga ttcctgaatc\n     3241 atggatttgc taaagtgact gtatatactt atattcataa tttaaatgat taattctggt\n     3301 cagataaatg ttgttaaatt ttaaaaatgt tttattacat tacatcaaat aaagtttatt\n     3361 tgtagctgta ataaagcaaa ttaagtaacg atttttaatg gaa\n//\n\nLOCUS       XM_059169489            3396 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 7 (HTR7),\n            transcript variant X1, mRNA.\nACCESSION   XM_059169489\nVERSION     XM_059169489.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081293) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..3396\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="4"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..3396\n                     /gene="HTR7"\n                     /note="5-hydroxytryptamine receptor 7; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 11 Proteins"\n                     /db_xref="GeneID:131828667"\n     CDS             354..1700\n                     /gene="HTR7"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 7 isoform X1"\n                     /protein_id="XP_059025472.1"\n                     /db_xref="GeneID:131828667"\n                     /translation="MMDVNSSGRPDLYGHLRSLLLPEVGRGLPDLSPDGAGPVSGSWA\n                     PHLLRGVPEVTASPVPTWDAPPDNASGCGEQINYGRAEKVVIGSILTLITLLTIAGNC\n                     LVVISVCFVKKLRQPSNYLIVSLALADLSVAVAVMPFVSVTDLIGGKWIFGHFFCNVF\n                     IAMDVMCCTASIMTLCVISIDRYLGITRPLTYPVRQNGKCMAKMILSVWLLSASITLP\n                     PLFGWAQNVNDDKVCLISQDFGYTIYSTAVAFYIPMSVMLFMYYQIYKAARKSAAKHK\n                     FPGFPRPEEPDSSISLNGMVKLQKEVEECANLSRLLKHERKNISIFKREQKAATTLGI\n                     IVGAFTVCWLPFFLLSTARPFICGTACSCIPLWVERTFLWLGYANSLINPFIYAFFNR\n                     DLRTTYRSLLQCQYRNINRKLSAAGMHEALKLAERPERPEFVLQNSDYCRKKSHDS"\n     polyA_site      3396\n                     /gene="HTR7"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 ctgccgctgc ctgccgggcg cgctcggccg aggcgcgcgg cggctgcggg ctgcggggcg\n       61 gccagccgag cggcgcccgc gggcccgtga gccgcgcgtc gcgggcgtcc gtctgtgtcg\n      121 ggggcgcctc ccgcggggag tctcggcgcg gtcgtgctcc cgcgtggtcc gcagcggctg\n      181 gggccccggg acgtgcgggg ccgcggggcc gagccgaggc gccccccagc ggccggcgcg\n      241 ggtcccatgg ctgggccggg cggagcggaa ccggcgaggt gaagcccccg ggccggaggc\n      301 cggagcgcgt ggcgggggcg ccggctccat gggcagcagc gcacagcggc acgatgatgg\n      361 acgttaacag cagcggccgc ccggacctct acgggcacct ccgctctttg ctcctgccgg\n      421 aggtggggcg cgggctgccg gacctgagcc ccgacggcgc cggcccggtc tcgggctcct\n      481 gggcgccgca cctgctgcgc ggggtcccag aggtgacggc cagcccggtg cccacctggg\n      541 acgcgccgcc ggacaatgcc tccggctgcg gggagcagat caactatggc agagccgaga\n      601 aagttgtgat cggctccatc ctgacgctca tcacgctgct gacgatcgca ggcaactgcc\n      661 tggtggtgat ctcggtgtgc ttcgtcaaga agctccgcca gccctccaac tacctgatcg\n      721 tgtccctggc gctggccgac ctctcggtgg ccgtggcggt catgcccttc gtcagcgtca\n      781 ccgacctcat cgggggcaag tggatctttg gccacttctt ctgcaacgtc ttcatcgcca\n      841 tggacgtcat gtgctgcacg gcctcgatca tgaccttatg cgtgatcagc atcgacaggt\n      901 acctcgggat cacgcggccg ctcacgtacc ccgtgaggca gaacggcaag tgcatggcga\n      961 aaatgattct gtctgtctgg ctgctttcag cctccatcac cttacccccg ctcttcggtt\n     1021 gggctcagaa cgtgaacgac gacaaggtgt gcctgatcag ccaggacttt ggctacacca\n     1081 tctactccac ggcagtggcg ttttacatcc ccatgtccgt catgctgttc atgtactacc\n     1141 agatctacaa ggctgcgcgg aagagcgccg ccaagcacaa gttccccggt ttcccccggc\n     1201 ccgaggagcc agacagcagc atctccctga acggcatggt gaagctccag aaggaggtgg\n     1261 aggagtgtgc caacctttcg agactcctca aacacgagag gaaaaacatc tccatcttca\n     1321 agcgggagca gaaagcggcc accaccttgg gcatcatcgt gggggccttc accgtgtgct\n     1381 ggctgccgtt cttccttctc tccaccgcca gacccttcat ctgcggcacg gcctgcagct\n     1441 gcatcccgct gtgggtggag aggacctttc tgtggctggg ctacgccaac tctctcatta\n     1501 acccttttat atatgccttc ttcaaccggg atctgaggac cacctaccgc agcctgctcc\n     1561 agtgccagta ccggaacatc aaccgcaagc tgtcggctgc aggcatgcac gaagccctga\n     1621 agctcgccga gaggcccgag agacctgagt ttgtgctaca aaactctgac tactgtagga\n     1681 aaaaaagtca tgattcatga tcaaacgtgg aataatgaaa acgaaatcaa caaggcaaga\n     1741 cagaggtgga aacagaactc aaccatttgc tgaggccgcg gaatggagcg cggcttgtcc\n     1801 tttcctgggg tggctgagac gtgacaagca gagtgatctg ttgtacaaag catgttgtga\n     1861 gagagatggt gacctcttgt ctttttctgt ggatcagtgc tgttgtgtgc caaagaaaat\n     1921 agttttccgt ttaagacggc cagatcagct cagcggtaag cacacaaaca gaactgagtc\n     1981 ccagaaaaga agccgtttct ggtgctttgt gtacgtccaa gcccctacaa atggaagaaa\n     2041 gttccaatgc gcacttccca tgcttccaag tctaggcatt gtggtgaata ttcaggaatc\n     2101 atttacgaga cagaatgtat tttgtggcag gacagaaggg tgtgtttttc caagcaaact\n     2161 gtggtaagcg tagcgttgaa tgtgttgcat gtccgtgtta gaaaacagaa tcccgtcatc\n     2221 agctaataca aatgatgtcc cagagcagtg tctggttcaa gcttctgtca aatagttttg\n     2281 cttttttgca gggtccctgt gacttcccca ccgatgtact tttctttgtg aactcttgta\n     2341 ttgttatggt atcactcagg aacagatctc aggatggaga gaatcatcaa acctaaataa\n     2401 agctttttct tgtactcaca cttcttctga agggtcctga gaggggagga gggttccttt\n     2461 ggtaggcttt gtacctacct ggatgaagag caggggccac tgaactgtgc tgtctaccag\n     2521 catggctgtg ggcataaaac ttcaggtgta gatatcaggt tgacacaact gtggtgggct\n     2581 cccaggccgg acaataacca tgtgttttgg gggaggaagt atgggaataa gaaaggtttc\n     2641 catgggaagt tatgatgctt tcagacatgg agcatcaaca ttgttaattc ttgggcagca\n     2701 ttgtattaaa gggaaccatg tgacttggag gtcacctggg ctgctactgg gaaacactca\n     2761 gaacactatt ctcttccttt aggaggattt gttttcatgt tctctgtaac ctaaatcaaa\n     2821 tgtgtgcctg gccagttctg ttcttcttcc ctctccctcc tcaaagtggt agacatgaag\n     2881 gcaggtaaac cagaaaaggc cctgatgcaa atagtttgtt gggttttttt gttttgtttt\n     2941 tgtttttaat gtacaagtaa tatgtaataa gacaggaaga tggtggatcg gaagagtacc\n     3001 tccaagggga gaaagtgaac acaaagtttt gtttgataaa agagaactga cagagaaaat\n     3061 tattttccta caagaaaggt agctgttctc ttccagaaga ctatggaatt ccaacgtgga\n     3121 ttttggatat cttctgcttt cactgaacat tgcatctcac cagacacaag gaagggtcta\n     3181 gaggggaggt gggtgctgtc ctctcagaca aagcttgtac agattcctga atcatggatt\n     3241 tgctaaagtg actgtatata cttatattca taatttaaat gattaattct ggtcagataa\n     3301 atgttgttaa attttaaaaa tgttttatta cattacatca aataaagttt atttgtagct\n     3361 gtaataaagc aaattaagta acgattttta atggaa\n//\n\nLOCUS       XM_059167735            2208 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 2B\n            (HTR2B), transcript variant X4, mRNA.\nACCESSION   XM_059167735\nVERSION     XM_059167735.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081292) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..2208\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="3"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..2208\n                     /gene="HTR2B"\n                     /note="5-hydroxytryptamine receptor 2B; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 1 Protein"\n                     /db_xref="GeneID:131827347"\n     CDS             136..1317\n                     /gene="HTR2B"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 2B isoform X4"\n                     /protein_id="XP_059023718.1"\n                     /db_xref="GeneID:131827347"\n                     /translation="MLRKLTRRVADLLVGLFVMPIALLTIMFEAMWPLPLVLCPAWLF\n                     LDVLFSTASIMHLCAISVDRYIAIKKPIQANQYNSRATALIKITVVWLISIGIAIPVP\n                     IRGIEIDAGNPSNITCVLTKDRFGNFMLFGSLAAFFTPLAIMIVTYFLTIQALQKKAY\n                     LVKNKQPQRLTWLAVSTVFQSSKETPCSSPEKVAMLDSSHKGKTLPNSSGKIQRRRMS\n                     TVGKKSVQNISNEQRASKVLGIVFFLFLLMWCPFFITNITLVLCDSCNQTTLKMLLEV\n                     FVWIGYVSSGVNPLVYTLFNKTFRNAFGRYISCNYRAMKSVKTVRKCSSNTYFRNPRA\n                     ENSKFFMKHGMRNGINPAMFQSPMRLRSSNTQVSSIILLDTLLLTEHEGDKTEEQVSY\n                     V"\n     polyA_site      2208\n                     /gene="HTR2B"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 ttccttggca tgcctgtagc tctacaacac atttgtttca ttgcttttaa gcgtctgtgt\n       61 gggaggctct gaataagtca atgagaggac ttcagtcaga gaagcactgc agatctactg\n      121 agcagatcag atgacatgct caggaaatta acaagaagag tggctgattt gctggttgga\n      181 ttgtttgtga tgccgattgc cctcttgaca ataatgtttg aggctatgtg gcccctccca\n      241 cttgttctat gccctgcctg gttatttctt gatgttcttt tttctactgc atccatcatg\n      301 catctctgtg ccatttccgt ggatcgttat atagccatca aaaagccaat ccaggccaat\n      361 caatataact cacgagccac agcactcatc aagattacag tggtatggct aatttcaata\n      421 ggcattgcca ttccagtacc catcagaggg atagaaattg atgcaggtaa cccaagcaac\n      481 atcacctgtg tgctgacaaa ggatcgtttt ggcaacttca tgctctttgg ctcactggct\n      541 gccttcttca cacctctggc aatcatgatt gtcacctact ttctcactat ccaagcttta\n      601 cagaagaaag cttatttggt caaaaacaag caacctcaac gcctaacatg gttggctgtg\n      661 tctacagtct tccaaagttc caaagaaaca ccttgctcat cacctgaaaa ggtggcaatg\n      721 ctggacagtt cccacaaagg caaaactctg cccaattcaa gtggtaagat acaaaggcga\n      781 agaatgtcca cagttggaaa aaagtctgtg cagaacattt ccaatgaaca gagagcctct\n      841 aaggttctag ggattgtttt ttttctcttt ttgcttatgt ggtgcccctt ttttattaca\n      901 aatataactt tagttttatg tgattcctgc aaccagacta ctctcaaaat gctcctagag\n      961 gtatttgtgt ggataggcta tgtttcttca ggggtgaatc ctttggtcta caccctcttc\n     1021 aataagacat ttcggaacgc gtttggccga tacatcagct gcaattaccg ggccatgaaa\n     1081 tcagtaaaaa ctgtcagaaa atgttccagc aatacctact tccgaaatcc aagggcagag\n     1141 aactccaagt ttttcatgaa acatggaatg agaaatggga ttaatcctgc catgttccag\n     1201 agcccaatga ggctccgcag ttcaaacact caggtttcct caatcattct attagataca\n     1261 cttctcctca cagaacatga gggtgacaaa actgaagagc aagtcagtta tgtatagaag\n     1321 gaatgtcagt tttcatctaa ttaatataac aatgaattag gtgatgaaga tgatataaat\n     1381 gtaccaagaa ttataaaaga agaactttat gtcatgtata aaatcacctc tttaaaacaa\n     1441 gaggtatcta taaagatgta caattttctt tatttggaca aaactactcc atgaaaaaaa\n     1501 ttattctgta tagctgaaag caaaaacaat ccagaagtct ggctaaatgt taaggtattc\n     1561 aaatgaaata aaattaagta aatcagtaag tttcagtctt aaaaataaac aatgtcattg\n     1621 taagaatttg tttagttcct aactgtatga aagctgtgct aagaatgaaa taagacaaaa\n     1681 aagcattacc ctcttcaaag ccttaaaaac acaaggcgta acacagaaca acaatgagag\n     1741 gaacagaaga ctaaaaataa gtgcacagaa tgatcgcatc tggaggtaag ctaagattgt\n     1801 cactgcagtc tggctcagtt aaaggcagtc acgatattgc tttgatctag aaacttgtga\n     1861 cggaaggggt agggaagggc ggttgttggg tatcacacaa agtaatagga tctcggaact\n     1921 agagctgttt gttaaatgtc tgataccagg tacatctact caccagaagt gggtctaact\n     1981 tagagaacga gaggatgcaa atgaaatcac tccagcatac ctaaaattca ttttgttcct\n     2041 tggagaacaa gtacaaactg gaaacacagg atcttgatcc aggaacctaa actttaatga\n     2101 ccccataatg accccaacac ttggctaaac tggcacattt tttattcacc ctttcctaat\n     2161 ttcactgtgc actgctagat ctgggaataa atccaaactg tgtcacca\n//\n\nLOCUS       XM_059167734            2301 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 2B\n            (HTR2B), transcript variant X3, mRNA.\nACCESSION   XM_059167734\nVERSION     XM_059167734.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081292) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..2301\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="3"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..2301\n                     /gene="HTR2B"\n                     /note="5-hydroxytryptamine receptor 2B; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 3 Proteins"\n                     /db_xref="GeneID:131827347"\n     CDS             88..1410\n                     /gene="HTR2B"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 2B isoform X3"\n                     /protein_id="XP_059023717.1"\n                     /db_xref="GeneID:131827347"\n                     /translation="MKQTGEQQGNKPRWAALLILLVIIPTIGGNILVILAVSLEKKLQ\n                     YATNYFLMSLAVADLLVGLFVMPIALLTIMFEAMWPLPLVLCPAWLFLDVLFSTASIM\n                     HLCAISVDRYIAIKKPIQANQYNSRATALIKITVVWLISIGIAIPVPIRGIEIDAGNP\n                     SNITCVLTKDRFGNFMLFGSLAAFFTPLAIMIVTYFLTIQALQKKAYLVKNKQPQRLT\n                     WLAVSTVFQSSKETPCSSPEKVAMLDSSHKGKTLPNSSGKIQRRRMSTVGKKSVQNIS\n                     NEQRASKVLGIVFFLFLLMWCPFFITNITLVLCDSCNQTTLKMLLEVFVWIGYVSSGV\n                     NPLVYTLFNKTFRNAFGRYISCNYRAMKSVKTVRKCSSNTYFRNPRAENSKFFMKHGM\n                     RNGINPAMFQSPMRLRSSNTQVSSIILLDTLLLTEHEGDKTEEQVSYV"\n     polyA_site      2301\n                     /gene="HTR2B"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 gtcagagaag cactgcagat ctactgagca gatcagatga catgctcagg aaattaacaa\n       61 gaagagacag aatcgatacc agaggaaatg aaacagactg gtgagcaaca gggaaataaa\n      121 ccacgctggg cagctcttct gatactcctt gtgataatac ccaccattgg tgggaacatc\n      181 cttgttattc tggctgtttc actggagaaa aagctgcagt atgctactaa ttattttcta\n      241 atgtccctgg cagtggctga tttgctggtt ggattgtttg tgatgccgat tgccctcttg\n      301 acaataatgt ttgaggctat gtggcccctc ccacttgttc tatgccctgc ctggttattt\n      361 cttgatgttc ttttttctac tgcatccatc atgcatctct gtgccatttc cgtggatcgt\n      421 tatatagcca tcaaaaagcc aatccaggcc aatcaatata actcacgagc cacagcactc\n      481 atcaagatta cagtggtatg gctaatttca ataggcattg ccattccagt acccatcaga\n      541 gggatagaaa ttgatgcagg taacccaagc aacatcacct gtgtgctgac aaaggatcgt\n      601 tttggcaact tcatgctctt tggctcactg gctgccttct tcacacctct ggcaatcatg\n      661 attgtcacct actttctcac tatccaagct ttacagaaga aagcttattt ggtcaaaaac\n      721 aagcaacctc aacgcctaac atggttggct gtgtctacag tcttccaaag ttccaaagaa\n      781 acaccttgct catcacctga aaaggtggca atgctggaca gttcccacaa aggcaaaact\n      841 ctgcccaatt caagtggtaa gatacaaagg cgaagaatgt ccacagttgg aaaaaagtct\n      901 gtgcagaaca tttccaatga acagagagcc tctaaggttc tagggattgt tttttttctc\n      961 tttttgctta tgtggtgccc cttttttatt acaaatataa ctttagtttt atgtgattcc\n     1021 tgcaaccaga ctactctcaa aatgctccta gaggtatttg tgtggatagg ctatgtttct\n     1081 tcaggggtga atcctttggt ctacaccctc ttcaataaga catttcggaa cgcgtttggc\n     1141 cgatacatca gctgcaatta ccgggccatg aaatcagtaa aaactgtcag aaaatgttcc\n     1201 agcaatacct acttccgaaa tccaagggca gagaactcca agtttttcat gaaacatgga\n     1261 atgagaaatg ggattaatcc tgccatgttc cagagcccaa tgaggctccg cagttcaaac\n     1321 actcaggttt cctcaatcat tctattagat acacttctcc tcacagaaca tgagggtgac\n     1381 aaaactgaag agcaagtcag ttatgtatag aaggaatgtc agttttcatc taattaatat\n     1441 aacaatgaat taggtgatga agatgatata aatgtaccaa gaattataaa agaagaactt\n     1501 tatgtcatgt ataaaatcac ctctttaaaa caagaggtat ctataaagat gtacaatttt\n     1561 ctttatttgg acaaaactac tccatgaaaa aaattattct gtatagctga aagcaaaaac\n     1621 aatccagaag tctggctaaa tgttaaggta ttcaaatgaa ataaaattaa gtaaatcagt\n     1681 aagtttcagt cttaaaaata aacaatgtca ttgtaagaat ttgtttagtt cctaactgta\n     1741 tgaaagctgt gctaagaatg aaataagaca aaaaagcatt accctcttca aagccttaaa\n     1801 aacacaaggc gtaacacaga acaacaatga gaggaacaga agactaaaaa taagtgcaca\n     1861 gaatgatcgc atctggaggt aagctaagat tgtcactgca gtctggctca gttaaaggca\n     1921 gtcacgatat tgctttgatc tagaaacttg tgacggaagg ggtagggaag ggcggttgtt\n     1981 gggtatcaca caaagtaata ggatctcgga actagagctg tttgttaaat gtctgatacc\n     2041 aggtacatct actcaccaga agtgggtcta acttagagaa cgagaggatg caaatgaaat\n     2101 cactccagca tacctaaaat tcattttgtt ccttggagaa caagtacaaa ctggaaacac\n     2161 aggatcttga tccaggaacc taaactttaa tgaccccata atgaccccaa cacttggcta\n     2221 aactggcaca ttttttattc accctttcct aatttcactg tgcactgcta gatctgggaa\n     2281 taaatccaaa ctgtgtcacc a\n//\n\nLOCUS       XM_059167733            2590 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 2B\n            (HTR2B), transcript variant X2, mRNA.\nACCESSION   XM_059167733\nVERSION     XM_059167733.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081292) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..2590\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="3"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..2590\n                     /gene="HTR2B"\n                     /note="5-hydroxytryptamine receptor 2B; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 1 Protein"\n                     /db_xref="GeneID:131827347"\n     CDS             320..1699\n                     /gene="HTR2B"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 2B isoform X2"\n                     /protein_id="XP_059023716.1"\n                     /db_xref="GeneID:131827347"\n                     /translation="MTSLATDHADHCPELDHITRKHHITRKQRMGFSYRISEQSRIPE\n                     HILQSSFHHLIFANWSELQTESIPEEMKQTVADLLVGLFVMPIALLTIMFEAMWPLPL\n                     VLCPAWLFLDVLFSTASIMHLCAISVDRYIAIKKPIQANQYNSRATALIKITVVWLIS\n                     IGIAIPVPIRGIEIDAGNPSNITCVLTKDRFGNFMLFGSLAAFFTPLAIMIVTYFLTI\n                     QALQKKAYLVKNKQPQRLTWLAVSTVFQSSKETPCSSPEKVAMLDSSHKGKTLPNSSG\n                     KIQRRRMSTVGKKSVQNISNEQRASKVLGIVFFLFLLMWCPFFITNITLVLCDSCNQT\n                     TLKMLLEVFVWIGYVSSGVNPLVYTLFNKTFRNAFGRYISCNYRAMKSVKTVRKCSSN\n                     TYFRNPRAENSKFFMKHGMRNGINPAMFQSPMRLRSSNTQVSSIILLDTLLLTEHEGD\n                     KTEEQVSYV"\n     polyA_site      2590\n                     /gene="HTR2B"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 atttgtttca ttgcttttaa gcgtctgtgt gggaggctct gaataagtca atgagaggac\n       61 ttcagtcaga gaagcactgc agatctactg agcagatcag atgacatgct caggaaatta\n      121 acaagaagag ctatcagatt ctttcactaa gccttctgaa atctgagcct ctgcagaaga\n      181 ctaaaccctg gggccttacc tacagaaacg gacagaagct tgtatgctct cattttcaag\n      241 aacccaaaaa tttttttaaa ggaagaagtc aactttggct ttgagtgttt ggcctgggta\n      301 caatgccttt aaaaagcaga tgaccagctt agctaccgac catgcagacc attgtccgga\n      361 attggatcac atcacacgaa aacatcacat cacacgaaaa cagcgaatgg gcttctctta\n      421 cagaatatca gaacagagca gaattcctga gcacattttg cagagctcct ttcatcactt\n      481 aatctttgct aactggtctg aattacagac agaatcgata ccagaggaaa tgaaacagac\n      541 tgtggctgat ttgctggttg gattgtttgt gatgccgatt gccctcttga caataatgtt\n      601 tgaggctatg tggcccctcc cacttgttct atgccctgcc tggttatttc ttgatgttct\n      661 tttttctact gcatccatca tgcatctctg tgccatttcc gtggatcgtt atatagccat\n      721 caaaaagcca atccaggcca atcaatataa ctcacgagcc acagcactca tcaagattac\n      781 agtggtatgg ctaatttcaa taggcattgc cattccagta cccatcagag ggatagaaat\n      841 tgatgcaggt aacccaagca acatcacctg tgtgctgaca aaggatcgtt ttggcaactt\n      901 catgctcttt ggctcactgg ctgccttctt cacacctctg gcaatcatga ttgtcaccta\n      961 ctttctcact atccaagctt tacagaagaa agcttatttg gtcaaaaaca agcaacctca\n     1021 acgcctaaca tggttggctg tgtctacagt cttccaaagt tccaaagaaa caccttgctc\n     1081 atcacctgaa aaggtggcaa tgctggacag ttcccacaaa ggcaaaactc tgcccaattc\n     1141 aagtggtaag atacaaaggc gaagaatgtc cacagttgga aaaaagtctg tgcagaacat\n     1201 ttccaatgaa cagagagcct ctaaggttct agggattgtt ttttttctct ttttgcttat\n     1261 gtggtgcccc ttttttatta caaatataac tttagtttta tgtgattcct gcaaccagac\n     1321 tactctcaaa atgctcctag aggtatttgt gtggataggc tatgtttctt caggggtgaa\n     1381 tcctttggtc tacaccctct tcaataagac atttcggaac gcgtttggcc gatacatcag\n     1441 ctgcaattac cgggccatga aatcagtaaa aactgtcaga aaatgttcca gcaataccta\n     1501 cttccgaaat ccaagggcag agaactccaa gtttttcatg aaacatggaa tgagaaatgg\n     1561 gattaatcct gccatgttcc agagcccaat gaggctccgc agttcaaaca ctcaggtttc\n     1621 ctcaatcatt ctattagata cacttctcct cacagaacat gagggtgaca aaactgaaga\n     1681 gcaagtcagt tatgtataga aggaatgtca gttttcatct aattaatata acaatgaatt\n     1741 aggtgatgaa gatgatataa atgtaccaag aattataaaa gaagaacttt atgtcatgta\n     1801 taaaatcacc tctttaaaac aagaggtatc tataaagatg tacaattttc tttatttgga\n     1861 caaaactact ccatgaaaaa aattattctg tatagctgaa agcaaaaaca atccagaagt\n     1921 ctggctaaat gttaaggtat tcaaatgaaa taaaattaag taaatcagta agtttcagtc\n     1981 ttaaaaataa acaatgtcat tgtaagaatt tgtttagttc ctaactgtat gaaagctgtg\n     2041 ctaagaatga aataagacaa aaaagcatta ccctcttcaa agccttaaaa acacaaggcg\n     2101 taacacagaa caacaatgag aggaacagaa gactaaaaat aagtgcacag aatgatcgca\n     2161 tctggaggta agctaagatt gtcactgcag tctggctcag ttaaaggcag tcacgatatt\n     2221 gctttgatct agaaacttgt gacggaaggg gtagggaagg gcggttgttg ggtatcacac\n     2281 aaagtaatag gatctcggaa ctagagctgt ttgttaaatg tctgatacca ggtacatcta\n     2341 ctcaccagaa gtgggtctaa cttagagaac gagaggatgc aaatgaaatc actccagcat\n     2401 acctaaaatt cattttgttc cttggagaac aagtacaaac tggaaacaca ggatcttgat\n     2461 ccaggaacct aaactttaat gaccccataa tgaccccaac acttggctaa actggcacat\n     2521 tttttattca ccctttccta atttcactgt gcactgctag atctgggaat aaatccaaac\n     2581 tgtgtcacca\n//\n\nLOCUS       XM_059167732            2743 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 2B\n            (HTR2B), transcript variant X1, mRNA.\nACCESSION   XM_059167732\nVERSION     XM_059167732.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081292) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..2743\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="3"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..2743\n                     /gene="HTR2B"\n                     /note="5-hydroxytryptamine receptor 2B; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 9 Proteins"\n                     /db_xref="GeneID:131827347"\n     CDS             320..1852\n                     /gene="HTR2B"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 2B isoform X1"\n                     /protein_id="XP_059023715.1"\n                     /db_xref="GeneID:131827347"\n                     /translation="MTSLATDHADHCPELDHITRKHHITRKQRMGFSYRISEQSRIPE\n                     HILQSSFHHLIFANWSELQTESIPEEMKQTGEQQGNKPRWAALLILLVIIPTIGGNIL\n                     VILAVSLEKKLQYATNYFLMSLAVADLLVGLFVMPIALLTIMFEAMWPLPLVLCPAWL\n                     FLDVLFSTASIMHLCAISVDRYIAIKKPIQANQYNSRATALIKITVVWLISIGIAIPV\n                     PIRGIEIDAGNPSNITCVLTKDRFGNFMLFGSLAAFFTPLAIMIVTYFLTIQALQKKA\n                     YLVKNKQPQRLTWLAVSTVFQSSKETPCSSPEKVAMLDSSHKGKTLPNSSGKIQRRRM\n                     STVGKKSVQNISNEQRASKVLGIVFFLFLLMWCPFFITNITLVLCDSCNQTTLKMLLE\n                     VFVWIGYVSSGVNPLVYTLFNKTFRNAFGRYISCNYRAMKSVKTVRKCSSNTYFRNPR\n                     AENSKFFMKHGMRNGINPAMFQSPMRLRSSNTQVSSIILLDTLLLTEHEGDKTEEQVS\n                     YV"\n     polyA_site      2743\n                     /gene="HTR2B"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 atttgtttca ttgcttttaa gcgtctgtgt gggaggctct gaataagtca atgagaggac\n       61 ttcagtcaga gaagcactgc agatctactg agcagatcag atgacatgct caggaaatta\n      121 acaagaagag ctatcagatt ctttcactaa gccttctgaa atctgagcct ctgcagaaga\n      181 ctaaaccctg gggccttacc tacagaaacg gacagaagct tgtatgctct cattttcaag\n      241 aacccaaaaa tttttttaaa ggaagaagtc aactttggct ttgagtgttt ggcctgggta\n      301 caatgccttt aaaaagcaga tgaccagctt agctaccgac catgcagacc attgtccgga\n      361 attggatcac atcacacgaa aacatcacat cacacgaaaa cagcgaatgg gcttctctta\n      421 cagaatatca gaacagagca gaattcctga gcacattttg cagagctcct ttcatcactt\n      481 aatctttgct aactggtctg aattacagac agaatcgata ccagaggaaa tgaaacagac\n      541 tggtgagcaa cagggaaata aaccacgctg ggcagctctt ctgatactcc ttgtgataat\n      601 acccaccatt ggtgggaaca tccttgttat tctggctgtt tcactggaga aaaagctgca\n      661 gtatgctact aattattttc taatgtccct ggcagtggct gatttgctgg ttggattgtt\n      721 tgtgatgccg attgccctct tgacaataat gtttgaggct atgtggcccc tcccacttgt\n      781 tctatgccct gcctggttat ttcttgatgt tcttttttct actgcatcca tcatgcatct\n      841 ctgtgccatt tccgtggatc gttatatagc catcaaaaag ccaatccagg ccaatcaata\n      901 taactcacga gccacagcac tcatcaagat tacagtggta tggctaattt caataggcat\n      961 tgccattcca gtacccatca gagggataga aattgatgca ggtaacccaa gcaacatcac\n     1021 ctgtgtgctg acaaaggatc gttttggcaa cttcatgctc tttggctcac tggctgcctt\n     1081 cttcacacct ctggcaatca tgattgtcac ctactttctc actatccaag ctttacagaa\n     1141 gaaagcttat ttggtcaaaa acaagcaacc tcaacgccta acatggttgg ctgtgtctac\n     1201 agtcttccaa agttccaaag aaacaccttg ctcatcacct gaaaaggtgg caatgctgga\n     1261 cagttcccac aaaggcaaaa ctctgcccaa ttcaagtggt aagatacaaa ggcgaagaat\n     1321 gtccacagtt ggaaaaaagt ctgtgcagaa catttccaat gaacagagag cctctaaggt\n     1381 tctagggatt gttttttttc tctttttgct tatgtggtgc ccctttttta ttacaaatat\n     1441 aactttagtt ttatgtgatt cctgcaacca gactactctc aaaatgctcc tagaggtatt\n     1501 tgtgtggata ggctatgttt cttcaggggt gaatcctttg gtctacaccc tcttcaataa\n     1561 gacatttcgg aacgcgtttg gccgatacat cagctgcaat taccgggcca tgaaatcagt\n     1621 aaaaactgtc agaaaatgtt ccagcaatac ctacttccga aatccaaggg cagagaactc\n     1681 caagtttttc atgaaacatg gaatgagaaa tgggattaat cctgccatgt tccagagccc\n     1741 aatgaggctc cgcagttcaa acactcaggt ttcctcaatc attctattag atacacttct\n     1801 cctcacagaa catgagggtg acaaaactga agagcaagtc agttatgtat agaaggaatg\n     1861 tcagttttca tctaattaat ataacaatga attaggtgat gaagatgata taaatgtacc\n     1921 aagaattata aaagaagaac tttatgtcat gtataaaatc acctctttaa aacaagaggt\n     1981 atctataaag atgtacaatt ttctttattt ggacaaaact actccatgaa aaaaattatt\n     2041 ctgtatagct gaaagcaaaa acaatccaga agtctggcta aatgttaagg tattcaaatg\n     2101 aaataaaatt aagtaaatca gtaagtttca gtcttaaaaa taaacaatgt cattgtaaga\n     2161 atttgtttag ttcctaactg tatgaaagct gtgctaagaa tgaaataaga caaaaaagca\n     2221 ttaccctctt caaagcctta aaaacacaag gcgtaacaca gaacaacaat gagaggaaca\n     2281 gaagactaaa aataagtgca cagaatgatc gcatctggag gtaagctaag attgtcactg\n     2341 cagtctggct cagttaaagg cagtcacgat attgctttga tctagaaact tgtgacggaa\n     2401 ggggtaggga agggcggttg ttgggtatca cacaaagtaa taggatctcg gaactagagc\n     2461 tgtttgttaa atgtctgata ccaggtacat ctactcacca gaagtgggtc taacttagag\n     2521 aacgagagga tgcaaatgaa atcactccag catacctaaa attcattttg ttccttggag\n     2581 aacaagtaca aactggaaac acaggatctt gatccaggaa cctaaacttt aatgacccca\n     2641 taatgacccc aacacttggc taaactggca cattttttat tcaccctttc ctaatttcac\n     2701 tgtgcactgc tagatctggg aataaatcca aactgtgtca cca\n//\n\nLOCUS       XM_059166673            2327 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 5B\n            (LOC131826933), mRNA.\nACCESSION   XM_059166673\nVERSION     XM_059166673.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081292) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..2327\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="3"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..2327\n                     /gene="LOC131826933"\n                     /note="5-hydroxytryptamine receptor 5B; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 7 Proteins"\n                     /db_xref="GeneID:131826933"\n     CDS             412..1566\n                     /gene="LOC131826933"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 5B"\n                     /protein_id="XP_059022656.1"\n                     /db_xref="GeneID:131826933"\n                     /translation="MSLSGSRDPPPRAMEAANLSVAATSVALPQGPEACSMGPSPSGV\n                     VGSTTAGDSALPGGREPPFSVFTVLVVTLLVLLIAATFLWNLLVLVTILRVRAFHRVP\n                     HNLVASTAVSDVLVAALVMPLSLVSELSAGRRWRLGRSLCHVWISFDVLCCTASIWNV\n                     AAIALDRYWTITRHLQYTLRTRRRASALMIALTWALSALIALAPLLFGWGEAYDARRQ\n                     RCQVSQEPSYAVFSTCGAFYLPLGVVLFVYWKIYKAAKFRFGRRRRAVLPLPAPVQVK\n                     EAPHEAEMVFTARRPVVAFQMSGDSWREQKEKRAAVMVGILIGVFVLCWIPFFLAELI\n                     SPLCACSLPPIWKSIFLWLGYSNSFFNPLIYTAFNKNYNNAFKSLFSKQR"\n     polyA_site      2327\n                     /gene="LOC131826933"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\nORIGIN      \n        1 gcggcatgat ggcctgcctg gtgttcagca cccgccctcc cgggtgcagc ccggcccctg\n       61 cggccgcccg ctgtgggtgg gagcacctct ccaagcccgc ccctgcgcgc ggacactcgg\n      121 cggcgctccc agattcccag ccctgtgaca gcccgttgcc ccggggacgg cgcggagagg\n      181 tgggagggcc cggcgcaccg agcccagctg gactcccgag ggggtcccac tctctttttt\n      241 ccctctactg gaaaggaagt ccactagggc tccgagccaa aagggggctg tgaaccaagg\n      301 agggacaagg tagggcgact tggacacctg ccccccgtcc ttccggggca cgtagcgacc\n      361 ccttccacgc ccgcacctgc cgggtccacg cgagccccgg gaggagcgct tatgtccctg\n      421 tcgggaagcc gggatccccc gccgcgcgcc atggaagccg ctaacctctc ggtggccgcc\n      481 accagcgttg cccttcccca gggccccgaa gcctgcagca tgggcccgag ccccagcggg\n      541 gtcgttgggt cgacaaccgc gggcgattcc gccctgccgg ggggccgcga gccgcctttc\n      601 tccgtcttca cggtgctggt ggtgacgctg ctggtgctgc tgatcgcggc cactttcctg\n      661 tggaacctgc tggttctggt caccattctg cgtgtccgcg ccttccatcg tgtgccgcac\n      721 aatttggtgg cctcgacggc cgtgtcagac gtgctcgtgg cggcgctggt gatgcccctg\n      781 agcctggtga gcgagctgtc ggccgggcga cgctggcggt tgggccggag cctgtgccac\n      841 gtgtggatct ccttcgacgt gctgtgttgc acggccagca tctggaacgt ggcggccatc\n      901 gccctggacc gctactggac catcacgcgc cacctgcagt acacgctgcg cacccgccgc\n      961 cgcgcctcgg cgctcatgat cgcgctcacc tgggcgctct cggcgctcat cgccctagcg\n     1021 ccgctgctct tcggctgggg tgaggcgtac gatgcgcggc gccagcgctg ccaggtgagc\n     1081 caggagccct cctacgccgt cttctccacc tgcggcgcct tctacctgcc gcttggcgtg\n     1141 gtgctgttcg tctactggaa gatctacaag gcggccaagt ttcgtttcgg ccgccgccgc\n     1201 cgggcagtgc tgccgctgcc cgcccccgtg caggtgaagg aggcccctca cgaggcggag\n     1261 atggtgttca cggcgcggcg cccggtggtg gcctttcaga tgagcgggga ctcgtggcgg\n     1321 gagcagaagg agaagcgggc cgccgtgatg gtgggcattc tcatcggcgt gtttgtactg\n     1381 tgctggatcc ccttcttcct ggcggagctc atcagccccc tctgtgcctg cagcctgccc\n     1441 cccatctgga aaagcatctt cttgtggctg ggctactcca attctttctt taaccccctg\n     1501 atttacacag cgtttaacaa gaactacaac aacgccttca agagcctctt cagcaagcag\n     1561 agataaatcc agggctcggg aagacacgta ggtagggctg tgcgcaggga actggtatct\n     1621 ctgcccgctc caggcatctg ggagccttgc cccacagcgg agtagtgaag acgtcagccg\n     1681 taccacggcc cggaccgtag gagaagcgat gcccacggct ctctggaaag attgcgcatg\n     1741 tgcggcaagc gtgcctgtgg gtcctcttcc ggggtgtgtg gcagacatag ctaatcgatc\n     1801 gtggcacgtt tctccacgga gcaggacgtc tgccttggga tcctttgcag acagcgctct\n     1861 agttactgct aactggttgg aatggacaaa agagtcgaag ctgacttgcc tttcctttaa\n     1921 taccctattt ctctgagcgg atccgtctgc accgagcccc agtggcccac tttagggccc\n     1981 actaaaaagt gtctagtgca acccctatct actgaatcag gctttcagag aagtctgatc\n     2041 atttatatca ttgagctctt ttttcatcag tgagagacag tgctggatgc ttagactgtc\n     2101 tttagaccaa ttaaattggc cttcccgaag gggcaggggt ggtgagaccc aggcaggagt\n     2161 gtgttttaaa gctccctagg ggattctact gtgcagccgg ccagtgttga ggaccccggt\n     2221 gctgtccttt ctctgcttcc caacaaggga gagcccctat gagaaatgtt cccagcactc\n     2281 caccatatgg acttgtatgt gtaataaaaa tacttttgaa gcattga\n//\n\nLOCUS       XR_009351162             959 bp    RNA     linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 1F\n            (HTR1F), transcript variant X5, misc_RNA.\nACCESSION   XR_009351162\nVERSION     XR_009351162.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081291) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..959\n                     /organism="Mustela lutreola"\n                     /mol_type="transcribed RNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="2"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..959\n                     /gene="HTR1F"\n                     /note="5-hydroxytryptamine receptor 1F; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon."\n                     /db_xref="GeneID:131825233"\n     misc_RNA        1..959\n                     /gene="HTR1F"\n                     /product="5-hydroxytryptamine receptor 1F, transcript\n                     variant X5"\n                     /experiment="COORDINATES: polyA evidence [ECO:0006239]"\n                     /db_xref="GeneID:131825233"\nORIGIN      \n        1 gagatcacaa gaaggtagag cagcaggcag agagagagag ggaagcaggc tccttgctga\n       61 gcagagagcc cgacgacgtg gggctccatc ccaggacccc gagaccgtga cctgagccga\n      121 agacagaggc tttacccact aagccactca ggtgccccaa caaatgcatt ctaaaaggaa\n      181 gaatgatcct aggtccatga tcttcattcc attcagaaga aggaagaatc tcttaaagcc\n      241 ttccgaattg ttctttaaca gtgcaagatc tcttggattc tggacttcgg tgtcatgcaa\n      301 attcggctac atatcctgtg tcagtggctc tgaaactgtc agcctcctac cctccattcc\n      361 gttatcactg gaatagcatt ccttaaggtt cttcaagcca ataagattgt ggattttcta\n      421 ttgaagtttt agctacccta catgatgaag acctgtgcct atcgtcagtt gaaaagtcat\n      481 atatatggga agcccactcc gtgtgattcc attctaccaa gtgttgattt gtctccaacg\n      541 tctgtctact tttggacact atctagtgcc ttcagagcta ttaacaaaaa ggggccttac\n      601 ctgttcaacg tctgtgctaa ttaatagtca cagctgcagc ctggacatcc tcctgaagaa\n      661 tgcaaaggat acctggaccc taactgagct gaattaaaga aaggggttta cagtccatct\n      721 accattttgt atgattgcct aatgttttcc agccactgtg cttggcatta ttttatcatg\n      781 tcacccaaga tagaacatct ttgtatcttt tttttaaatt aattagttga aagaactcta\n      841 agtgatttaa ttttaaaagt aggtctacct aacttaaatt tttggactct gtaaatgaca\n      901 tgaaaaaatg ttcttggcat caaaatttaa tcatttaaaa tttgatcagt tctccacta\n//\n\nLOCUS       XM_059164430            8521 bp    mRNA    linear   MAM 23-AUG-2023\nDEFINITION  PREDICTED: Mustela lutreola 5-hydroxytryptamine receptor 1F\n            (HTR1F), transcript variant X4, mRNA.\nACCESSION   XM_059164430\nVERSION     XM_059164430.1\nDBLINK      BioProject: PRJNA1006319\nKEYWORDS    RefSeq.\nSOURCE      Mustela lutreola (European mink)\n  ORGANISM  Mustela lutreola\n            Eukaryota; Metazoa; Chordata; Craniata; Vertebrata; Euteleostomi;\n            Mammalia; Eutheria; Laurasiatheria; Carnivora; Caniformia;\n            Mustelidae; Mustelinae; Mustela.\nCOMMENT     MODEL REFSEQ:  This record is predicted by automated computational\n            analysis. This record is derived from a genomic sequence\n            (NC_081291) annotated using gene prediction method: Gnomon.\n            Also see:\n                Documentation of NCBI\'s Annotation Process\n            \n            ##Genome-Annotation-Data-START##\n            Annotation Provider         :: NCBI RefSeq\n            Annotation Status           :: Full annotation\n            Annotation Name             :: GCF_030435805.1-RS_2023_08\n            Annotation Pipeline         :: NCBI eukaryotic genome annotation\n                                           pipeline\n            Annotation Software Version :: 10.1\n            Annotation Method           :: Gnomon; cmsearch; tRNAscan-SE\n            Features Annotated          :: Gene; mRNA; CDS; ncRNA\n            Annotation Date             :: 08/17/2023\n            ##Genome-Annotation-Data-END##\nFEATURES             Location/Qualifiers\n     source          1..8521\n                     /organism="Mustela lutreola"\n                     /mol_type="mRNA"\n                     /isolate="mMusLut2"\n                     /isolation_source="Germany"\n                     /db_xref="taxon:9666"\n                     /chromosome="2"\n                     /sex="male"\n                     /tissue_type="blood"\n                     /dev_stage="adult"\n                     /country="Germany"\n                     /lat_lon="51.1657 N 10.4515 E"\n                     /collection_date="2022-03-14"\n                     /collected_by="Jakub Skorupski"\n     gene            1..8521\n                     /gene="HTR1F"\n                     /note="5-hydroxytryptamine receptor 1F; Derived by\n                     automated computational analysis using gene prediction\n                     method: Gnomon. Supporting evidence includes similarity\n                     to: 20 Proteins"\n                     /db_xref="GeneID:131825233"\n     CDS             776..1873\n                     /gene="HTR1F"\n                     /codon_start=1\n                     /product="5-hydroxytryptamine receptor 1F"\n                     /protein_id="XP_059020413.1"\n                     /db_xref="GeneID:131825233"\n                     /translation="MDFLNSSDQNLTSEELLNRMPSKILVSLTLSGLALMTTTINSLV\n                     IAAIIVTRKLHHPANYLICSLAVTDFLVAVLVMPFSIVYIVRESWIMGQVVCDIWLSV\n                     DITCCTCSILHLSAIALDRYRAITDAVEYSRKRTPKHAGIMITVVWIISIFISMPPLF\n                     WRHQGTSRDDECIIKHDHIVSTIYSTFGAFYIPLTLILILYYKIYKAAKTLYHKRQAS\n                     RIAKEEVNGQVLLGSGEKSTRLVSTPYTEKSLSDPSTDFDKIHNTVKSPRSEFKHEKS\n                     WRRQKISGTRERKAATTLGLILGAFVICWLPFFVKELVVNVCEKCKISEEMSNFLTWL\n                     GYLNSLINPLIYTIFNEDFKKAFQKLVRCRC"\nORIGIN      \n        1 atcgttaaaa aagaaaaagg taacagttaa aaaaaattgt acccgaaggc gagaaaaaaa\n       61 aaatgaaaaa gaaaaaatta aattaactgc aagactaaaa aaaaatcaca ggaaaaatgc\n      121 catgagttcc gtgcttggct ttctcctcct ctggaattct gctgctctcc ttggtattga\n      181 aaccgcactc cttggtaggt gaacttggtc tcggctggat ttcttgttga tcttctgggg\n      241 gaggggcctg ttgtagtgat tctcaagtgt ctttgcccca ggcggaattg caccgccctt\n      301 atcaggggcc gggtgagtta tccgctgggg tttgctttca ggagcttttg ttccctgagc\n      361 gctttccgta gagttccaga ggacgggaat acaaatggcg gcctcctggt ctccggcccg\n      421 gaggagccga gagcccaggg ccgcactcct cagtgcgccc tcagagaaca gcgcccagtt\n      481 actcccgtct gcctgacctc cggccgcgct ccgagctcac cgagcctggg accggttcaa\n      541 ggttcttcaa gccaataaga ttgtggattt tctattgaag ttttagctac cctacatgat\n      601 gaagacctgt gcctatcgtc agttgaaaag tcatatatat gggaagccca ctccgtgtga\n      661 ttccattcta ccaagtgttg atttgtctcc aacgtctgtc tacttttgga cactatctag\n      721 tgccttcagg tatccatttt ttcagctata ttaatctttt aaaacaaaca aaaaaatgga\n      781 tttcttaaac tcatctgatc aaaacttgac ctcagaagaa ctgttaaaca gaatgccatc\n      841 caaaattctg gtgtccctca ctctctccgg gctggcactg atgacaacga ccatcaactc\n      901 ccttgtgatt gcggcaatta ttgtgacccg gaagttgcac cacccagcca actatttaat\n      961 ttgctcgctt gcagtcacag attttcttgt agctgtcctg gtgatgcctt tcagcatcgt\n     1021 gtatattgtg agagagagct ggattatggg gcaagtggtc tgtgacatct ggctgagcgt\n     1081 tgacatcacg tgctgcacgt gttccatctt acatctctct gctatagctt tggatcggta\n     1141 tcgggcaatc acagatgctg tggagtactc caggaaaagg actcccaagc atgctggcat\n     1201 tatgattaca gttgtttgga ttatatccat ttttatctct atgcctcctt tattctggag\n     1261 gcaccaagga actagccgag atgatgagtg catcatcaaa cacgaccaca ttgtttccac\n     1321 aatttattca acatttggag ctttctacat cccattaaca ttgattttga tcctctacta\n     1381 caaaatatat aaagcagcaa aaacgttata ccacaagaga caagcaagta ggattgccaa\n     1441 ggaggaggtg aatggccaag tccttttggg gagtggtgag aaaagcacta gactagtctc\n     1501 cactccctac acagaaaaat ctttatctga tccatcaaca gactttgata aaattcataa\n     1561 cacggtgaaa agccccaggt ctgaattcaa gcacgagaaa tcttggagaa ggcaaaagat\n     1621 ctcaggcaca agagaacgca aagcagccac taccctagga ttaatcttgg gtgcatttgt\n     1681 gatatgttgg ctgcctttct ttgttaaaga attggttgtt aatgtctgtg aaaagtgtaa\n     1741 aatttctgaa gaaatgtcaa attttttgac atggcttgga tatctcaatt cccttataaa\n     1801 tccactgatt tatacaatct ttaatgaaga cttcaagaaa gcattccaaa agctagtacg\n     1861 atgccgatgt taaagaaagt ttatcattaa aaggctgggg atttcttgag gggaagtaac\n     1921 gaaatggatg ccgaataata aagcatttaa acttttagaa ggaaataaat taaaactact\n     1981 aaaattataa gaacataatt tatatttaac agcaacaaga ctataaattt actgagtaaa\n     2041 agatgtttct ttgaccatca ttctagagta ctcaaatgaa aagataattt attgtttata\n     2101 aacaataatt tccctatgca attgtcccta acaggctaac tggaaatata tattataata\n     2161 gttattatta ataacagtga ctttccaggt ttatggctta taatagttac agaaaagtgt\n     2221 tcacttcaca atatctgtaa tttctatata atcctatggt tttattatat gattctatta\n     2281 ttttatagaa aagataattc accacaaagc acacatttct cctacctaac cactgtcccc\n     2341 tcttcatctt accctgggaa aaaacaagaa ggggaaggag caaacaaggc atcttggggt\n     2401 gtctggctgg ctcaatcagg agagcatatg actcgagctc agggttgagt ttgaacacca\n     2461 cgttgtgtat aatgattact taaaaataaa atctttaaac aaaacaagac aaacaaacaa\n     2521 acaaaaccaa ggactcctaa tatgactgga ggaaatgtca aagtcagaga ttgatactgt\n     2581 cttagtattt atataataaa gagtattcat aaagttgagt tgggctttgc cagataattc\n     2641 tgaatacaga acttgtacac atttgacata ttctttttgt tcaaaacgaa ttcctaggat\n     2701 aatatttttt aaccatgtat taccaacata tgaaatcaaa accttagcct aataagagta\n     2761 attcaaaaag ggtacagggg aggtgttcta attgccccat gtttatttag gaatcacatt\n     2821 taaggcacta agtgccctag gttactcacc atagttacta tattcctaat gtgtttttta\n     2881 aaatacaaaa tagatttcgt ttctgttaat attaacaacc tcagttgcta aataaaatgt\n     2941 cagtggtact tggtactgca gctgttccat atctacaatt taaaaattat aaccgttaaa\n     3001 aaaacaaaaa ataataaata aataatccct tttattagag ggaatgttac aggagttctt\n     3061 agaactgccc actgacttcc aaaacatctc tcgtttttca attggtagaa atcgacaggc\n     3121 aaagattcat attatgttaa ttataaatat attttttaaa catctcccag tcagttagcc\n     3181 aaagctatgc cataagtttc tctatttatt ctctttctta tagaagaatt taaaaataaa\n     3241 ataaccatgc ttcagagatc tcattccatt tgaaccagca agttgatagg ctgccttctg\n     3301 gaaggcatac accatcaacc aagatcattt gaaaaacaat acattccttt tttttaaggt\n     3361 acacttttat gtgtatttta aatattgttt cctggtcaga tacttaagaa tacatcaatt\n     3421 tttgtgtata tctatgacac attactctca atctaacaaa tatttacagt tctcattctg\n     3481 tgtagggcat tgagatacag aaaataatga aacgcagtta cttcccttaa cacatttaca\n     3541 atttaaaagg tgaaacacac tgggcacctg gctgggtaga tcatacaact cttgatcttg\n     3601 gggtcatgca ttcaacccca catagagctt actttaaaaa ataagaagat gaaacaaaga\n     3661 aacaaatgaa cattataaca gaaaagaaaa aacaaagctc tggcatggaa gttgtgtgca\n     3721 taattatgat gattcaaagg aaaagttgat cacatctggt tgagaaaaat cagcaaaatt\n     3781 tcataaagaa tgtatctaaa atagataata aatagcattt ggctaagaga aatggaaaag\n     3841 catactccag gtggcggcaa catcaggagt gaatcctgcc agcatttcgt gggtcttgtt\n     3901 catgaaatag caaggaattt ggcagctcct taggacaaaa gaagagatga aaagagaaat\n     3961 tggccattat tgtcactgac tttgagtatc agaaaaggaa gtttacggtc aatttggctg\n     4021 tctgtcaatg agtggtcgct gatgttttta gtagaaatat tacaagttta ggttaattct\n     4081 aaaaaaatat gtatgtttta atggatttga gcagagaggg tacaggtgac agcgacttct\n     4141 tgttagaaag catatcagta atccacataa gaggtgaagt tctgaacttg attctagcca\n     4201 tgggaacata aataaaaaca cagaagagag acagtaggga aaaagaatct atagaataca\n     4261 gcaaggacgc taacaagcag ataaatgcag agacactgag ataacttgct ctcaactaaa\n     4321 atgagctcaa gaggggcacc tgggtggctc agtgggttaa agcctctgcc ttcggctcag\n     4381 gttatgatcc cagggtcctg ggatcgagcc ccgcatcggg ctctctgctc cgcagagagc\n     4441 ctgcttcctc ctctctctct ctctctgcct acttgtgatc tctgtctgtc aaataaataa\n     4501 ataaaatctt taaaaaaaaa aaaaaatgag ctcaagagaa ggagcctgtt ggtgaaatgg\n     4561 tgccttgagt taaacattta aagttaaatg ttaaacactt aaagacttgg gagagctcac\n     4621 aggcatggct gagcaggtct ggcccaagtg aaaatgactc agtttatctg cgactactgg\n     4681 ccacctcttt catcttcctt tcttctatct ccttatgctg tgctgacagt ccaaagccta\n     4741 ctctagtccc taccattttc tgcttgttct tcttgccgct tctcactaaa acttgattgt\n     4801 gatttattca ttcaaagacc ttgctaagtc agaaataatc tattcaagta atttatttac\n     4861 acccacctca gaaatttatt taggtatatg ggagagctct aaaagacaca caacccatcc\n     4921 accagaaaga gcaaatctca tgcaggtgag gctcacccga atatacatac taccttctcc\n     4981 tcggatctgg acgaagcctc aaatccaggg aaatgatact agcaagtgac agggaaatta\n     5041 aatctcccct cagagctcag ggagaatcga gtttattatt tctgtgtgta tgaaatacgt\n     5101 tcttaatcca aaggggccat aacacattat agtacttatc acttcatctt tgtatttcct\n     5161 ccacatgctg aaggtacaga tcatgccact cccatgaaca aatataaatg atttctcttt\n     5221 gatctttaaa tggtaggtaa tgtcagggct aataatctgc catttccaca ttaaaaaaaa\n     5281 aataaaataa aggccccaca gggcatcact gaggccaagt cacctaactg aggtgtaata\n     5341 cctaacctaa ctgcagtttc aacctccacc agaaatgtaa gttttaactt atatttagtc\n     5401 aggaattttc tgataagcac caatgaatga ggtaatctgt cacctgggtc ctctttgtcc\n     5461 cccaaggaag atgaagtaat ctgcataaga cctcctgctt ttccccctaa gggaaagtga\n     5521 ccttgcctgt tacaatcctt ttcttttact aataatttcc tcccccgcct tcttcctatg\n     5581 aaaaacttcc atttcatgca attcctcaga gctcctaatt catgaatcat ttaagaaagt\n     5641 caatttgatc ttcaaatcta ctcagttgaa tttctcttaa cagcactttc tttgaaattt\n     5701 atgaaggatg tacttccctg aatatataag atgtattctc ttaaggaaaa ttcctcaagt\n     5761 cactaaaagc tgaagatttt cacagagtat tttcacatct ataacaaatg taacaatatg\n     5821 ataatgtata tatttaactg ataagtagag aaagaaaata taagtatcat agaatgtggt\n     5881 taaatattag attaaaaaag tttaacttcc tgctacaatt tcaaatacac tagcatcaga\n     5941 gattaagtgg aggttttatt tttgctctgc tttttctaaa tattttcagg ttaaggatat\n     6001 ataaaaggca aggacaaaaa tatcaaagga agactgaaag tcaaactact agatatgaaa\n     6061 ttcagttcaa tacatcacta tgtataaatc atgtttgaaa atctgcttct ggttatgaag\n     6121 gactatcttt attttactgc tataggaata tggattgcct actttaatac tttttctgtt\n     6181 ggttttgttt cacaataggc ctacggggtc aaatttatag tatacacagt ttatccaggc\n     6241 cctggcagct gatgggtcta tctttaatgt aggcccagtt ctcattttgt atctctaaaa\n     6301 ccaatctttt ccctttcctg gtgcaactta tttccctccc ccacttctat tcctgagctc\n     6361 taacggtgtg caagtttccc gtttgcaagt caagaaaaac ttctttgggg ctcacttcca\n     6421 aatccttgct tatatgagtt atgtcacttc caaactttaa aattcccttg gtatatgggg\n     6481 cacctgggtg gctcagtcag ttaagtgtct gcctttgctc aagttatgat ctcatggtcc\n     6541 tgggatggag tcctgcatca gactccctgc tcagtgggga ggctgcttct ccctctcctg\n     6601 ctgctccccc tacctgtgct ctttctctct atcaaataaa taaaatctct aaaacaacaa\n     6661 agtaaggtaa aataaaataa aattccctta gtagagtata atcctcatat ttgttggctc\n     6721 tatcctaagc ttgtccctct gaagcaagag ttttgctaca gaaaactttt cttgttgtct\n     6781 gttttgcaga aaaacaaaat tttgtcaaaa cagacaacaa caaaaaaaat gaaatattaa\n     6841 ttgaaagcca attactagaa aatgtgttgt cttgctctac caaattttga tgtgaaatat\n     6901 tgttcaagag caaacgatca aaaaaagagt tcttgaaatg tcttcgatgc aaaaaaggtg\n     6961 gttttattaa agcatgggga caagacccgt gggcagaaag agctgcactg gggttgtgag\n     7021 ggtcagctga ttatatactt tcaagctggg aagggtttag ggaaattgta aatctttaag\n     7081 gaatttagaa gcaaggcttt caggattttg aggggctagc tgtaattaaa ataatgtctt\n     7141 tcactactgt ctgctaaaac cttagtcatg agaccttcgg atgtgtatct gtgggccata\n     7201 tgtttggagt agggttgcta acatacttct tgggggaaaa gagataaagg aagtctccaa\n     7261 agggattttc ataagttaaa gacttacaca atcctggagg tagggctaac atcagctaag\n     7321 gttacctttt gcctctacca aagtgtacaa gtgttaacaa tgagttagtt gagctcctgg\n     7381 aggaaggtca ttttgcctgt ctcagttact tgacaataag cagttaagtt gtaaggaaat\n     7441 ttaatttttt ttgtttttgt ttttgttttt ttgctgttgt tctcacatca aatatcatga\n     7501 aagtaaggga gcttgtatgc ttcttgttga catgctttcc tctacatcaa ggaatgaata\n     7561 gttgcctcgt gaatttagac aagagctttc ttgacttaca gtcagagaat cgggtttatt\n     7621 atattgcaga gcaaggactg aaggattttt ccttattata ttctaaagtc cttcagaaac\n     7681 aatcatgttc aattcagaat gtgtccccat tcattccttt cagagaatgt gttcctaata\n     7741 tcctcctaat aaactcaaat gatcacattc agacctttat tcaccagaag atatttctaa\n     7801 aggcaagtta atatttttga catgaataaa gtaatatttt ctcatgatat tgtggtagtt\n     7861 tttcttggtc ttatgaatca gtatgttttc tccattattt aaaatgaagt tgttgttgaa\n     7921 aaaaatgttt tccaacatta taataaatgt gtggttattg atataggacg tcttctctgt\n     7981 ataaaacatg atagtagtac ttgaaaccca ccggcaaaga taaagatttt tcagaattta\n     8041 tactctctac ttatgccagg aagcataaaa attctgaggg aaaaaaaatg tgtaatctct\n     8101 ttatcaatag taaacaacaa tgtcttgtcc aagcagcctt tcagtaaagc tggcatttag\n     8161 tcacaggtct gatttctacc ttggagagtt tccacctctg caagggcaac taaatgacct\n     8221 tattgattta tgtccacaca gcaaagtttg ctgtgtcttt cctcctagtc tcaccaatag\n     8281 ccttttcatg atgttctatg aatattccta atttatatgt aattgatatt cactcctaaa\n     8341 aagtatactt attgtatcat catattttat attgaatcat tattaattat tataatgtat\n     8401 tatgttgttg ggtctcctgc tttgagattt cctttacccc aatccactta ataaataaaa\n     8461 attttgctca tccccacccc cctccacaca tgtatacatc aacaatttcc tccttgtgtt\n     8521 g\n//\n\n'



Save as a new file: <span style="color: green">'5htr.gb'</span>


```python
with open('5htr.gb', 'w') as file_out:
    file_out.write(data)
```
