# ROAD 2 DEV
### Video Demo: <https://youtu.be/ynjUINLg5DU?si=4v7krtMMPtoBe446>
### Description: A web site with software development projects and with technology related subjects.
TODO

This project is a web site with my projects and codes about software development, it has also
sections with the main subjectios of technology sector, like web development, mobile, ai,
data science, cybersecurity and game development.

The project has a folder called images with all the 36 images used all over the website, it has also 10 html files, 8 css files and 1 md file.

* the index.html file:

Its a file with the homepage of the website, that is divided by 4 sections: the nav menu, the carousel, the thumbnail images and the footer. The images inside the carousel and thumbnails lead to another pages of the site. Inside of it we have html, javascript, jquery, bootstrap and css.

At the head, we have the meta tags describing the content, it has also the link and script tags with the libraries and apis needed.
With this links and scripts we are calling the java script, jquery, bootstrap and css files and libraries.

At the beggining of the body tag, we have the first div tag for the first section of the site with a placeholder for the nav. html, that contains the nav menu that will apeear throuout the site, the placeholder is called by the first function inside the script tag with the jquery code.

After that we have a container in which the layout of the site will be structured with several rows ans columns from bootstrap librarie, it contain the second and third sections.

The second section has the carousel with a carousel slide class, 4 carousel indicators and 2 buttons. Inside the carousel inner, we have 4 carousel items that lead to 4 distinct pages by clicking them, the fulanos, cs50, back-end and front-end pages.

In the third section, we have the thumbnail images that leads to another 6 pages of the site: web dev, mobile, ai, analytics, data science and cybersecurity.

All the 6 thumbnail images have the app efect provided by the javascript code inside the script tag, basiclly, when the mouser is over them.

Inside the script tag, the javascript code start by putting all the images inside an array, after that, a loop is called and will iterate over all the images inside the array, so, whem the mouse cursor is over them it will add a border to the left and right side of the images and remove the borders otherwise.

It give the images the ilusion of moviment, like whem we have to select a movie or serie in a streaming app.

Finally, we have the footer tag in which are all of my contacts and the copyright rights. Inside of it we have a div tag with a placeholder for the footer.html, that contains the infos that will apeear throuout the site, the placeholder is called by the function inside the script tag with the jquery code.

* the styles_index.css file:

It is related to the index.html file and at the beggining we have the font-face rule, that define the font-family biome w04 regular and its related urls to search.

After that we have all the media querie with the rules that will make the page reesponsive to small and large screens, inside of it is determined the fonts sizes, width and height of several elements, like the carousel and the container.

Inside of it i have made a several classes to estize the fonts and other elements with shadows, borders, colors, radius, position, alignment, margin and sizing.

* The nav.html file:

Its a bootstrap kind of menu, it is organized inside a div tag with a container class in wich we have a navbar-brand with the road 2 dev logo, a button of the type collapse that will present itself when displayed in small screens, otherwise the 4 elements will be show side by side on the right corner of the container.

Inside the navbar we have 4 links, home, projects, biography and contact me, where the project link is a dropdown menu with more 4 links: fulanos game, cs5o, back-end and front-end.

All of them leads to another oages, except for the contatc me link, that opens the cliente e-mail box to send me a message.

* The footer.html file:

Its a default footer that will be showned througout the site, it has the links to my other profissional pages, like linkedin and github, with its respectives logos and also the copyright rights and the link to e-mail me.

It follows the style of the styles_index.css by the link inside the header.

* The styles_nav.css file:

It determines the font-face rule and also the colors, shadows, text alignments, positions and border of the nav elements.

* The fulanos.html file:

Its a file with the Fulanos Game, it is divided by 4 sections: the nav menu, the game itself provided by an integration with the MIT Scratch software API, the images of the game with its descriptions, and the footer. Inside of it we have html, javascript, jquery, bootstrap and css.

At the head, we have the meta tags describing the content, it has also the link and script tags with the libraries and apis needed.
With this links and scripts we are calling the java script, jquery, bootstrap and css files and libraries.

At the beggining of the body tag, we have the first div tag for the first section of the site with a placeholder for the nav. html, that contains the nav menu that will apeear throuout the site, the placeholder is called by the first function inside the script tag with the jquery code.

The second function inside the script gets the iframe tag by its id and blocks it on the client screen, it will only appear whem the button is clicked, so the button and the image desapiers, reveling the game iframe.

After that we have a container in which the layout of the site will be structured with several columns from bootstrap librarie, it contain the second and third sections.

The second section has the fulanos game itself inside of the div with the btn-wrap class, divided by the iframe with game link, the game image and the button to display it.

When the button is clicked, the inicial page of the game is loaded and we have to press the green flag to start it, after a short history with the introduction of the game will take place.

At the end of the history, we have to press the space button to start the game, after that, all the cenario, the main personage, the obstacles and garbage will appear, we have to use the arrow keys to move the Fulanos monkey.

The main objective of this game is to collect the garbage and recycle them, with the right amount of if, will be able to make another usefull objects, like a new fork, a book, a ball, so on and so forth.

The more we collet and recycle the objets, more the city gets better, changing all the landscape. The game has 4 levels divided by a transition that occurs when the player collect the right amount of itens.

Later, the players will have a limited amount of life and will be able to collet other kinds os garbage to make more new objects, a major enemy will appear too before each transition and the monkey must take him down to continue.We will have also different kinds of landscapes.

In the third section, we have the images of the game introduction history and a brief explanation about why we have done this game with this main character, it also present the visual designer that made all of the game art.

Finally, we have the footer tag in which are all of my contacts and the copyright rights.

* the styles_fulano.css file:

It is related to the fulanos.html file and at the beggining we have the font-face rule, that define the font-family biome w04 regular and its related urls to search.

After that we have all the media queries with the rules that will make the page responsive to small and large screens, inside of it is determined the fonts sizes, width and height of several elements, like the iframe and the images.

Inside of it i have made a several classes to estize the fonts and other elements with shadows, borders, colors, radius, position, alignment, margin and sizing.

* The cs50.html file:

Its a file with the cs50 course explanation by week, it is divided by 3 sections: the nav menu, the several weeks with images and its texts and the footer. Inside of it we have html, javascript, jquery, bootstrap and css.

At the head, we have the meta tags describing the content, it has also the link and script tags with the libraries and apis needed.
With this links and scripts we are calling the java script, jquery, bootstrap and css files and libraries.

At the beggining of the body tag, we have the first div tag for the first section of the site with a placeholder for the nav. html, that contains the nav menu that will apeear throuout the site, the placeholder is called by the first function inside the script tag with the jquery code.

After that we have a container in which the layout of the page will be structured with several columns from bootstrap librarie, it contain the second section.

The second section has all the cs50 modules organized by weeks each one of them inside a div with the respective image with a link for other pages from this and external sites, it has as well texts explaining the week and another option to follow of the same links.

Finally, we have the footer tag in which are all of my contacts and the copyright rights. Inside of it we have a div tag with a placeholder for the footer.html, that contains the infos that will apeear throuout the site, the placeholder is called by the function inside the script tag with the jquery code.

* the styles_cs50.css file:

It is related to the cs50.html file and at the beggining we have the font-face rule, that define the font-family biome w04 regular and its related urls to search.

After that we have all the media queries with the rules that will make the page responsive to small and large screens, inside of it is determined the fonts sizes, width and height of several elements, like the iframe and the images.

Inside of it i have made a several classes to estize the fonts and other elements with shadows, borders, colors, radius, position, alignment, margin and sizing.

* The week1.html file:

Its a file with the all my codes from cs50 week 1, it is divided by 3 sections: the nav menu, the several problems with its codes and the footer. Inside of it we have html, javascript, jquery, bootstrap and css.

At the head, we have the meta tags describing the content, it has also the link and script tags with the libraries and apis needed.
With this links and scripts we are calling the java script, jquery, bootstrap and css files and libraries.

At the beggining of the body tag, we have the first div tag for the first section of the site with a placeholder for the nav. html, that contains the nav menu that will apeear throuout the site, the placeholder is called by the first function inside the script tag with the jquery code.

After that we have a container in which the layout of the page will be structured with several columns from bootstrap librarie, divided by practice problems, lab and problems set, all of it makes up the second section.

The second section has all the week 1 problems and each one of them is inside a div with the respective code, the comments explaining the code, a button and an input in which later the users will be able to run the codes.

After that, inside the second script tag, we have the javascrip code to run all of the codes inside each of the problems, it need to be finished.

Finally, we have the footer tag in which are all of my contacts and the copyright rights. Inside of it we have a div tag with a placeholder for the footer.html, that contains the infos that will apeear throuout the site, the placeholder is called by the function inside the script tag with the jquery code.

* the styles_week1.css file:

It is related to the cs50.html file and at the beggining we have the font-face rule, that define the font-family biome w04 regular and its related urls to search.

After that we have all the media queries with the rules that will make the page responsive to small and large screens, inside of it is determined the fonts sizes, width and height of several elements.

Inside of it i have made a several classes to estize the fonts and other elements with shadows, borders, colors, radius, position, alignment, margin and sizing.

* The backend.html file:

Its a file with the all my back-end codes from cs50 and from other sites and projects, it is divided by 3 sections: the nav menu, the several problems with its codes and the footer. Inside of it we have html, javascript, jquery, bootstrap and css.

At the head, we have the meta tags describing the content, it has also the link and script tags with the libraries and APIs needed.
With this links and scripts we are calling the java script, jquery, bootstrap and css files and libraries.

At the beggining of the body tag, we have the first div tag for the first section of the site with a placeholder for the nav. html, that contains the nav menu that will apeear throuout the site, the placeholder is called by the first function inside the script tag with the jquery code.

After that we have a container in which the layout of the page will be structured with several columns from bootstrap librarie with all my back-end codes, all of it makes up the second section.

All of the problems are inside a div with the respective code, the comments explaining the code, a button and an input in which later the users will be able to run the codes.

After that, inside the second script tag, we have the javascrip code to run all of the codes inside each of the problems, it need to be finished.

Finally, we have the footer tag in which are all of my contacts and the copyright rights. Inside of it we have a div tag with a placeholder for the footer.html, that contains the infos that will apeear throuout the site, the placeholder is called by the function inside the script tag with the jquery code.

* the styles_backend.css file:

It is related to the backend.html file and at the beggining we have the font-face rule, that define the font-family biome w04 regular and its related urls to search.

After that we have all the media queries with the rules that will make the page responsive to small and large screens, inside of it is determined the fonts sizes, width and height of several elements.

Inside of it i have made a several classes to estize the fonts and other elements with shadows, borders, colors, radius, position, alignment, margin and sizing.

* The frontend.html file:

Its a file with the all my front-end codes from cs50 and from other sites and projects, it is divided by 3 sections: the nav menu, the several problems with its codes and the footer. Inside of it we have html, javascript, jquery, bootstrap and css.

At the head, we have the meta tags describing the content, it has also the link and script tags with the libraries and APIs needed.
With this links and scripts we are calling the java script, jquery, bootstrap and css files and libraries.

At the beggining of the body tag, we have the first div tag for the first section of the site with a placeholder for the nav. html, that contains the nav menu that will apeear throuout the site, the placeholder is called by the first function inside the script tag with the jquery code.

After that we have a container in which the layout of the page will be structured with several columns from bootstrap librarie with all my front-end codes, all of it makes up the second section.

All of the problems are inside a div with the respective code, the comments explaining the code, a button and an input in which later the users will be able to run the codes.

After that, inside the second script tag, we have the javascrip code to run all of the codes inside each of the problems, it need to be finished.

Finally, we have the footer tag in which are all of my contacts and the copyright rights. Inside of it we have a div tag with a placeholder for the footer.html, that contains the infos that will apeear throuout the site, the placeholder is called by the function inside the script tag with the jquery code.

* the styles_frontend.css file:

It is related to the frontend.html file and at the beggining we have the font-face rule, that define the font-family biome w04 regular and its related urls to search.

After that we have all the media queries with the rules that will make the page responsive to small and large screens, inside of it is determined the fonts sizes, width and height of several elements.

Inside of it i have made a several classes to estize the fonts and other elements with shadows, borders, colors, radius, position, alignment, margin and sizing.

* The biography.html file:

Its a file with my biography, it is divided by 3 sections: the nav menu, my biography with images and texts, and finally the footer. Inside of it we have html, javascript, jquery, bootstrap and css.

At the head, we have the meta tags describing the content, it has also the link and script tags with the libraries and apis needed.
With this links and scripts we are calling the java script, jquery, bootstrap and css files and libraries.

At the beggining of the body tag, we have the first div tag for the first section of the site with a placeholder for the nav. html, that contains the nav menu that will apeear throuout the site, the placeholder is called by the first function inside the script tag with the jquery code.

After that we have a container in which the layout of the page will be structured with a row and columns from bootstrap librarie, it contain the second section.

The second section has my biography organized by 3 columns each one of them inside a div with a text explaing my profissional background, with my picture and my skills, divided by soft and hard ones.

Finally, we have the footer tag in which are all of my contacts and the copyright rights. Inside of it we have a div tag with a placeholder for the footer.html, that contains the infos that will apeear throuout the site, the placeholder is called by the function inside the script tag with the jquery code.

* the styles_biography.css file:

It is related to the biography.html file and at the beggining we have the font-face rule, that define the font-family biome w04 regular and its related urls to search.

After that we have all the media queries with the rules that will make the page responsive to small and large screens, inside of it is determined the fonts sizes, width and height of several elements, like the iframe and the images.

Inside of it i have made a several classes to estize the fonts and other elements with shadows, borders, colors, radius, position, alignment, margin and sizing.














