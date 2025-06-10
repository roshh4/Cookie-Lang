### Cookie Code Tunnel

This go server acts as a tunnel to run Cookie language code in a Docker container locally from other user...

#### To Use:

1.  **Start the Go Server:**

    First, cd into `backend/code_tunnel` , then run:
    ```bash
    go run tunnel.go
    ```
    This will start the server, listening on port `8080`.

2.  **Get a Public URL with ngrok:**

    To make your local server accessible from the internet, open the terminal and run ngrok:
    ```bash
    ngrok http 8080
    ```
    Ngrok will give you a public URL, copy this URL

<img width="1361" alt="Screenshot 2025-06-10 at 7 48 25 PM" src="https://github.com/user-attachments/assets/2d9f8e54-cca5-4aee-92ab-077bf3c8ea25" />



3.  **Send Your Cookie Code!**

    Now you can send your Cookie code to the public URL. You have two ways:


    *   **Send Code Directly (as a string):**

        ```bash
        curl -X POST -d 'print("Hello from Cookie!");' YOUR_NGROK_URL/run
        ```
        (Replace `YOUR_NGROK_URL` with the URL ngrok gave you)

    *   **Send Code from a File:**

        First, create a file (e.g., `my_code.cook`) with your Cookie code in it:
        ```cookie
        print("Hello from file!");
        ```
        Then send it using curl:
        ```bash
        curl -X POST -d @my_code.cook YOUR_NGROK_URL/run
        ```
        (Again, replace `YOUR_NGROK_URL`)

    The server will run your code in a Docker container (`alphastar59/cookie:latest`) and send the output back to your terminal.

#### Requirements:

*   Go 
*   Docker 
*   `alphastar59/cookie:latest` Docker image (pull if you don't have it: `docker pull alphastar59/cookie:latest`)
*   ngrok 
