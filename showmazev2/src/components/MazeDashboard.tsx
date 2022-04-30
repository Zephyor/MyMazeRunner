import React, { useState } from 'react';
import './MazeDashboard.css';
import MazeMap from './MazeMap';


const MazeDashboard = () => {
    
    const [selectedFile, setSelectedFile] = useState<string>('');
 
    const handleFileChange = (event: any) => {
        const file = event.target.files[0];
        console.log(event.target.files);
        const reader = new FileReader();
        reader.onload = ((evt: ProgressEvent<FileReader>) => {
            console.log(evt.target?.result);
            if (evt.target?.result !== null) {
                setSelectedFile(evt.target?.result as string);
            }
        });
        reader.readAsText(file);
    }

    return (
        <div className="maze-dashboard">
            <input type='file' onChange={handleFileChange}/>
            <MazeMap content={selectedFile}/>
        </div>
    );
}

export default MazeDashboard;