# Biopython
In this document you will have an introduction to _Biopython_ along with some
of its basic classes, their attributes and methods and other functions. We
have also prepared an [activity](#linkactivity) `Jupyter Notebook` document
with a workflow.


[Biopython][docu-biopython] is a set of Python libraries designed for biological
computations. It was developed collaboratively by an international team
with the goal to ease the parsing of different data types allowing instead,
to focus on actually working with the data. Some of _Biopython_'s  features
include the ability to:

- Work with sequence performing common operations like translation or transcription.
- Parse different sequence file formats like _BLAST, Clustalw, FASTA,
Genbank, ..._
- Connect with biological databases such as
_[NCBI](#https://www.ncbi.nlm.nih.gov/), 
[UniProt](#https://www.uniprot.org/)
or [Expasy](#https://www.expasy.org/about)_.
- Conduct supervised learning analyses (more in the  section 16 of the
[documentation](#docu-biopython)).
- Work with trees and phylogenetic procedures.
- Working with crystal structures of macromolecules.

However, in this session our goal is for you to get familiar with some of the
basic classes, functions, resources and other advantages of using _Biopython_ .


## Table of contents

1. [Installation](#installation)
2. [SeqIO](#seqio) 
     - [Import and export sequence files](#import-and-export-sequence-files)
        - [File conversions](#file-conversions)
3. [Essential modules and other useful tools](#essential-modules-and-other-useful-tools)
     - [SeqRecord](#seqrecord)
     - [Seq](#seq)
     - [Translation tables](#translation-tables)
4. [NCBI’s Entrez databases](#ncbi’s-entrez-database)


## INSTALLATION 

During the session's activity, you will be using _Biopython_ in a `Jupyter
Notebook`. In order to be able to use _Biopython_'s constructs you will have
to install it locally, there are several ways to do this. The first option
is to use python to install it without accessing any specific `Conda`
environments.

```
# python3 installation
pip3 install biopython
```

Alternatively, you could use `Conda` which allows to have _Biopython_ in
an isolated environment. We don't recommend it being installed in a specific 
environment however, this would mean having to activate the environment each
time you meant to use _Biopython_. To simply install it in the base environment
use the following command in the terminal.


```bash
# Conda installation
conda install biopython
```

## SeqIO

_Biopython_ allows to ease the process of working with bioinformatic-related
files and operations. This way, using _Biopython_, you will be able to use few
functions to what otherwise, would have taken many more lines of code. 

The `Bio.SeqIO` module is recommended as the first choice for manipulating
sequence data. It allows a straightforward and uniform way for reading and
writing sequence files in different formats, including multiple sequence
alignments. It processes sequences only as `SeqIO.SeqRecord` objects, you can
find more information on `SeqRecords` and its attributes on the 
[`SeqRecord`](#seqrecord) below on this file.

When working with `SeqIO` you will first need to import the module from the
_Biopython_ library, specifically `Bio` which is the main package in
_Biopython_. In order to do this you will use `from Bio import SeqIO`.



### IMPORT AND EXPORT SEQUENCE FILES


The `SeqIO` module recognises a total of 33 different file formats used to 
store sequences. You can access the list of file formats yourself using 
`SeqIO._FormatToIterator.keys()`. Some of these file formats that `SeqIO`
manages are _fasta_, _fastaq_ (which contains quality scores), 
_GenBank_ and _EMBL_ (which contain _annotations_) and others like _Nexus_
and _Phylip_.

>NOTE: You can also find more information about the different files,
in the [SeqIO documentation][SeqIO].

 <details>
    <summary><strong>To import files:</strong> SeqIO.parse() & SeqIO.read().</summary>
 <blockquote>

The main function in `SeqIO` is `Bio.SeqIO.parse()`. It takes
two arguments, a file's path and its format's name. It returns an object or an
iterator with objects of the [`SeqRecord`] class (you can find more information
on the [`SeqRecord`](#seqrecord) section). For example, when
inputting a `fasta` file with a single sequence:

```python
record = SeqIO.parse("input.fa", "fasta") 
```

In _Biopython_, there are multiple ways to do the same things. For example,
files containing only a single record can be read using the function
`SeqIO.read()`. This function takes same arguments as `SeqIO.parse()`
(e.g.`SeqIO.read("input.fa", "fasta"`)). If there is only one record in the
file, it is returned as a [`SeqRecord`](#seqrecord) object. Otherwise an
exception is raised.


If the file contains several sequences, however, we can store them in a list
the following way:

```python
records = list(SeqIO.parse("input.fa", "fasta"))
```

In this second case in order to access each of the instances in the 
_input.fa_ file, we need to index the _records_ list e.g. `records[0]`. 
As previously stated each of the elements of these instances, as the _record_
are all[`SeqRecord`](#seqrecord) class. 
</blockquote></details>


<details>
    <summary><strong>To export files:</strong> SeqIO.write().</summary>
<blockquote>

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
SeqIO.write(records, "output_file.fa" , "fasta")
```

This is the simple, straight-forward way, alternatively we can use 
`with open()`. In this second case, the output file is explicitly opened
using the `open()` function assigned to the variable after the `as` (file_out)
and then used in the `SeqIO.write()` as the file argument as we can see in
the example below. 

Using the `with open()`statement ensures that the file is properly closed
after writing. Both approaches achieve the same result, but using `with open()`
will allow you to perform additional operations. For example if the output file
isn't empty and your goal is to append the _records_ at the end of the file, 
you can easily achieve this by replacing the "w" in `open` by "a" (for append
mode). 


```python
# 1st create the file with the records content
with open("output_file.fa", "w") as file_out:
    SeqIO.write(records, file_out, "fasta")

# now at the end of the file add the records2 content
with open("output_file.fa", "a") as file_out:
    SeqIO.write(records2, file_out, "fasta")

```
</blockquote></details>

<details>
    <summary><strong>File conversions:</strong> SeqIO.convert()</summary>

<blockquote>

You can use existent files to create new files of different formats with the 
same content. You could read the file, using the `Bio.SeqIO.parse()` and pass
the `SeqRecord` iterator to the `Bio.SeqIO.write()` and save it using a 
different file format. However, `SeqIO` offers the `SeqIO.convert` function
which takes four arguments and does the this concisely. 

We need to keep in mind that some file formats contain more information
than others. For example, we can't turn a `fasta` file into a `fastaq`
file since we are missing the quality scores. However we can go from more
information to less. For example to turn a _GenBank_ file into a _Fasta_ file
we can use `SeqIO.convert()`. We give as arguments the name of the  input file
_cor6_6.gb_, the name of the file format, the name of the output file
 _cor6_6.fasta_ and the format we want it to be:

```python
from Bio import SeqIO
count = SeqIO.convert("cor6_6.gb", "genbank", "cor6_6.fasta", "fasta")
```


</blockquote>
</details>

## ESSENTIAL MODULES AND OTHER USEFUL TOOLS

The following sections are an introduction to the main modules and resources
we will be working with.

### SeqRecord 

The `SeqRecord` object used in _Biopython_ to hold a sequence, as a
[`Seq`](#seq) object, with identifiers `id` and `name`, description 
and optionally annotation and sub-features. We can import sequences
as `SeqRecord` objects using `parse()`, as we have seen in the previous 
section. Remember that to do this we must have imported `SeqIO` from
`Bio`. In addition, the `Bio` package also offers a _SeqRecord_ **module**,
which can be imported using `from Bio.SeqRecord import SeqRecord`. 
The following table contains
the `SeqRecord` attributes and the information they hold. 

 <details>
    <summary>View table.</summary>

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
           on a protein sequence). See more on section 4.3 of the [documentation].
           </td>
        </tr>
        <tr>
           <td>.dbxrefs</td>
           <td>A list of database cross-references as strings (e.g. ['Project:58037']).</td>
        </tr>
     </table>
</blockquote></details>

We will mainly be using the first 4 attributes. For example, the
`example1.fa` file contains only two lines:

<blockquote>
>example1 this is a simple example<br>
GATTACA-A
</blockquote>

We can import this sequence as a `SeqRecord` object using `parse()` the 
following way. 

```python
from Bio import SeqIO

record = SeqIO.parse("example1.fa", "fasta") 
[print(att) for att in list(record)]
```

The output shows the `SeqRecord` _record_ variable's attribute's content:
```
ID: example1
Name: example1
Description: example1 this is a simple example
Number of features: 0
Seq('GATTACA-A')
```

The `Seq` attribute is the minimum information needed to create an instance of
a `SeqRecord`. Like `SeqRecord`, the `Seq` object has it own set of attributes
and its own module `Bio.Seq` which can be imported using `from Bio.Seq import
Seq`. 

### Seq 

The `Seq` object essentially is a `Python` string containing a sequence. 
Because of this it can be iterated like a `string` and shares many of
the same methods like `len()` and `count()`. Additionally, it offers
further methods like the `translate()`, `complement()` and 
`reverse_complement()`. As previously stated, the `Seq`
module can imported using `from Bio.Seq import Seq`.


The following is an easy example. We create an instance of a `Seq` object:
_sequence_ and check the output of the main methods.

``` python
from Bio.Seq import Seq

sequence = Seq("GATTACA")

print(sequence.count("A"))
print(len(sequence))
print(sequence.transcribe())
print(sequence.reverse_complement())
print(sequence.translate())
```

When executing the chunk, you will get a warning notifying you that the string
is not multiple of 3 and suggesting to either trim the sequence or adding
trailing N before executing the `translate()` method. This is because
otherwise, the residual bases won't be accounted for (in this case the last
_Adenine_). The _output_ of the previous code, will show that the number of
_Adenines_ is 3, the length of the sequence is 7, the result of replacing Ts by
Us, its reverse complement is _TGTAATC_, and the obtained amino acids obtained 
starting at "GAT" are DY since the residual _A_ isn't accounted for. 

>NOTE: you can find more information on Seq methods and ways to deal with
them under the section 3.1 to 3.8 of the [Biopython Documentation][docu-biopython]

You need to keep in mind that like `Python` strings, `Seq` objects do not
support item assignments and in order to modify them, we need to
transform them into a `MutableSeq`object. To do this we need to import it
using `from Bio.Seq import MutableSeq` and transform the `Seq` sequence
though reassignment (e.g. `sequence = MutableSeq(sequence))`.



### Translation tables

The `Seq` objects contain the `translate()` method which performs translation
using an internal codon table objects derived from [NCBI][#NCBItable]. We can
import codon tables using `from Bio.Data import CodonTable`. We will only be 
importing the `Standard` table, whcih is the default translation table in
_GenBank_ but there are many more, you can check the [NCBI][#NCBItable] site
for more information. Additionally, we can also use
`from Bio.Data import IUPACData` to import a dictionary to change the symbols
of the amino acids from one to three (e.g. "G" to "Gly"). 

The following shows how we can import the `Standard` codon table: 

``` python
from Bio.Data import CodonTable

CodonTable.unambiguous_dna_by_name
codons = CodonTable.unambiguous_dna_by_name['Standard']

print(codons)
```

The output would be the default table with id 1: "Table 1 Standard, SGC0" which
currentl accepts _"TTG" and "CTG"_  in addition to _"ATG"_ as start codons
and the conventional _"TAA", "TAG" and "TGA" as stop codons. Again you can find
more information in the [NCBI][#NCBItable] cite. It looks the following:

<br>
<p align="left">
  <img width='390' height='400' src="https://github.com/AlbaJimLup/myTesting/assets/103122258/c124bae6-1454-4d2f-abdd-30fda21b6030">
</p>

>Note: The _codons_ variable has its own set of useful attributes. For example
the `start_codons` or `stop_codons` return a list of the start and the stop 
codons respectively and the `forward_table` is a dictionary with codon string as keys
(e.g. "ATG")  and their respective amino acids as values (e.g. "M").  




## NCBI's ENTREZ DATABASES

We have seen how we can parse sequence data from a local file. Now we will see
how we can use a network connection to download and parse sequences from the
internet into a `SeqRecord` object.


[_Entrez_][#Entrez] is a data retrieval system that allows access to
[_NCBI's_][#aboutNCBI] databases. Currently it includes 38 databases
covering a variety of biomedical data, including nucleotide and protein
sequences, gene records, three-dimensional molecular structures, and the
biomedical literature. Some of these databases include _PRF, Swiss-Prot,
PDB, GenBank_ and others.

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

There another five *EUtils* functions described on the sections 9.1 to 9.9 of
[_Biopython's documentation_][#docu-biopython] and you can find more
information on [_Entrez Programming Utilities on NCBI_][#utilities]’s page.
For now, just know  that _EUtils_ tools ensure that the correct URL is used
for the queries, and that NCBI’s guidelines for responsible data access are
being followed.

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

You have an example of the pipeline in the [activty workflow][#linkactivity]
 where we will retrieve data from `GenBank`.

  >NOTE: It is worth mentioning that as part of
  [_NCBI’s Entrez User Requirements_][#NCBI-Entrez-User-Requirements],
  `Bio.Entrez` will require for you to probide an email address with each call
  to  _Entrez_. This  will be used only to contact developers if _NCBI_
  observes requests that violate policies prior to blocking access. 


---

[aboutNCBI]: <https://www.ncbi.nlm.nih.gov/home/about/>
[docu-biopython]: <http://biopython.org/DIST/docs/tutorial/Tutorial.pdf>
[Entrez]: <https://www.ncbi.nlm.nih.gov/Web/Search/entrezfs.html>
[linkactivity] <https://www.github.com/deliablue/preparatoryweek_2023/biopython/BiopythonActivity1.ipynb>
[NCBI-Entrez-User-Requirements]: <#https://www.ncbi.nlm.nih.gov/books/NBK25497i/>
[NCBItable]:<https://www.ncbi.nlm.nih.gov/Taxonomy/Utils/wprintgc.cgi>
[SeqIO]: <https://biopython.org/wiki/SeqIO>
[utilities]: <https://www.ncbi.nlm.nih.gov/books/NBK25501/>

