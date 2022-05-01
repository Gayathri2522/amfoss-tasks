import argparse
from ast import arguments
import requests

cli_parser = argparse.ArgumentParser(description="To fetch image based on date and rover id")
cli_parser.add_argument("date",default="2015-6-3", type=str,help="Give date in YYYY-MM-DD format")
cli_parser.add_argument("r_id",default='5',type=int,help="Rover id for curiosity:5 Opportunity:6 spirit:7")
arguments = cli_parser.parse_args()

earthDate = arguments.date
roverId = arguments.r_id
#choosing rover according to the id parameter parsed
if roverId==5:
    roverName='curiosity'
elif roverId==6:
    roverName='opportunity'
elif roverId==7:
    roverName='spirit'
# f before the strings mean f-strings => all the all the variables inside curly brackets are read and replaced by their value
apiUrl = f"https://api.nasa.gov/mars-photos/api/v1/rovers/{roverName}/photos?earth_date={earthDate}&api_key=YRcw7t4uAtCVaRx3wUtphEiHhonVkiAKFc5jnNbc"

req = requests.get(apiUrl)
requestJSON = req.json()
no_of_images = 0
#if error is present, it will be the key instead of the JSON response
if 'error' in requestJSON:
    print(requestJSON['error'])
else:
    for image in requestJSON['photos']:
        print('The {}th Image is being saved'.format(no_of_images))
        imageSource = image['img_src']
        imageResponse = requests.get(imageSource)
        #this imageResponse is a whole object, we need to get the image by acessing its content
        image = imageResponse.content
        imagePath = open(f"image{no_of_images}.png",'wb')
        imagePath.write(image)
        no_of_images+=1
if no_of_images==0:
    print("Image not found for the given parameters")

