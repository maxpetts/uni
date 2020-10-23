<head>
<link href="https://fonts.googleapis.com/css2?family=Patua+One&family=Roboto&display=swap" rel="stylesheet"> 
<style>
table {
    border: 1px solid grey;
}
body {
    font-family: 'Roboto', sans-serif;
    padding: 5px;
    height: 90vh;

}
h1, h2{
    font-family: 'Patua One';
}
</style>
</head>

### ICP-3011 Computer & Network Security
----
# **Reflect And Relate** <img src='/Users/mp/Documents/uni/uni_logo.jpg' width='150px' align='right'/> 


## **Max Petts** *- eeub35*
### 📅 - 04.10.2020

----

## **Week 1** - SSH Remote Access
### Concepts learnt: 
 - Authentication
 - SSH (Secure SHell)
 - Cryptography (RSA Cryptosystem)

In order to ensure the appropriate actors(users) are able to access the correct areas of a system, but are denied access to other, the security system must be able to differentiate between users; this is identification. Authentication, on the other hand, is the act of validating the claimed identity. When discussing authentication the user being identified is called the Principal.

Authentication is apparent in many day to day tasks for example, when you get tested for Covid-19 the nurses will ask you to recite your name and address, as to verify you're the person you claim to be. This is called a credential and is used to verify the principal being claimed is entitled. Without this step Principal may get their test back positive, when it is actually negative, or visa versa. Some methods of authorization become less user friendly and laborious, if a credential

I use git to track changes to my projects, which requires a public key before any changes can be pushed to the repository; if this repo contained sensitive information then the key should use ECDSA, as RSA is vulnerable to [timing attacks[1]](http://crypto.stanford.edu/~dabo/papers/ssl-timing.pdf).

|     | References |
| --- | ---------- |
| [1] | http://crypto.stanford.edu/~dabo/papers/ssl-timing.pdf | 

## **Week 2** - GPG - *GNU Privacy Guard*
### Concepts learnt:
 - The CIA Triad 

CIA (Confidentiality, Integrity, Availability)
 Without can't gaurantee secure transfer of information at all.
Encryption ensures that transmitted data remains private 
## **Week 3** - E-Mail Spoofing
### Concepts learnt:
 - Security from the start
Building on top of previous security layers means nothing if not secure.

## **Week 4** - 'Real World' Cracking
### Concepts learnt:
- Validation
"Trust is the root of all compromise"
